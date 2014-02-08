#include <stdlib.h>
#include <stddef.h>
#include "type.h"
#include "embody.h"

#define container_of(ptr, type, member) \
	(type *)( (char *)ptr - offsetof(type, member) )

typedef struct {
	emb_type_id_t type_id;
	void *data;
} emb_container_t;


void ** emb_new(emb_type_id_t type_id, void *data_p)
{
	emb_container_t *embc;

	embc = malloc(sizeof(emb_container_t));
	embc->type_id = type_id;
	embc->data = data_p;

	return &(embc->data);
}

emb_type_id_t emb_type_id_wrapped(void **data_pp)
{
	emb_container_t *embc;
	
	embc = container_of(data_pp, emb_container_t, data);
	return embc->type_id;
}

void emb_free_wrapped(void **data_pp)
{
	emb_container_t *embc;
	void (*free_callback)(void *) = NULL;
	
	embc = container_of(data_pp, emb_container_t, data);

	// TODO: Free data
	free_callback = emb_type_get_callback(embc->type_id, "free");
	if (free_callback) {
		free_callback(embc->data);
	}
	embc->data = NULL;
	free(embc);
}
