#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "type.h"

typedef struct {
	char *name;
	emb_hash_table_t *callbacks;
} emb_type_t;

static emb_type_t * emb_type_new(const char *name)
{
	emb_type_t *type = NULL;
	size_t len;

	type = malloc(sizeof(emb_type_t));
	len = strlen(name);
	type->name = malloc(len + 1);
	strcpy(type->name, name);

	type->callbacks = emb_hash_table_new(16);

	return type;
}

static emb_type_t **emb_types = NULL;
static size_t emb_types_size = 0;

static void emb_types_initialize(void)
{
	if (emb_types == NULL) {
		emb_types_size = 256;
		emb_types = calloc(emb_types_size, sizeof(emb_type_t *));
	}
}

emb_type_id_t emb_type_get_id(const char *name)
{
	emb_type_id_t i = 0;

	emb_types_initialize();

	while (i < emb_types_size && emb_types[i] != NULL) {
		if (strcmp(emb_types[i]->name, name) == 0) {
			break;
		}
		i++;
	}

	if (i >= emb_types_size) {
		emb_types = realloc(emb_types, emb_types_size * 2 * sizeof(emb_type_t *));
		memset(emb_types + emb_types_size, 0, emb_types_size * sizeof(emb_type_t *));
		emb_types_size = emb_types_size * 2;
	}

	if (emb_types[i] == NULL) {
		emb_types[i] = emb_type_new(name);
	}

	return i;
}

const char * emb_type_get_name(emb_type_id_t type_id)
{
	const char *name = NULL;

	if (type_id < emb_types_size && emb_types[type_id] != NULL) {
		name = emb_types[type_id]->name;
	}

	return name;
}

int emb_type_register_callback(emb_type_id_t type_id, const char *name,
	void *callback)
{
	emb_hash_table_t *callbacks;

	if (type_id >= emb_types_size || emb_types[type_id] == NULL)
		return -1;

	callbacks = emb_types[type_id]->callbacks;

	return emb_hash_table_set(callbacks, name, callback, NULL);
}

void * emb_type_get_callback(emb_type_id_t type_id, const char *name)
{
	emb_hash_table_t *callbacks;

	if (type_id >= emb_types_size || emb_types[type_id] == NULL)
		return NULL;

	callbacks = emb_types[type_id]->callbacks;

	return emb_hash_table_get(callbacks, name);
}
