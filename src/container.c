#include <stdlib.h>
#include <stddef.h>
#include "type.h"
#include "container.h"

#define container_of(ptr, type, member) \
	(type *)( (char *)ptr - offsetof(type, member) )

typedef struct {
	emb_type_id_t type_id;
	void *data;
} emb_container_t;

void ** emb_container_new(emb_type_id_t type_id, void *data_p)
{
	emb_container_t *embc;

	embc = malloc(sizeof(emb_container_t));
	embc->type_id = type_id;
	embc->data = data_p;

	return &(embc->data);
}

emb_type_id_t emb_container_type_id(void **data_pp)
{
	emb_container_t *embc;

	embc = container_of(data_pp, emb_container_t, data);
	return embc->type_id;
}

void emb_container_free(void **data_pp)
{
	emb_container_t *embc;
	void (*free_callback)(void *) = NULL;
	
	embc = container_of(data_pp, emb_container_t, data);

	free_callback = emb_type_get_callback(embc->type_id, "free");
	if (free_callback) {
		free_callback(embc->data);
	}
	embc->data = NULL;
	free(embc);
}
