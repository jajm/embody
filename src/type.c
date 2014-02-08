#include <stdlib.h>
#include <string.h>
#include <libgends/hash_map.h>
#include "type.h"

typedef struct {
	char *name;
	gds_hash_map_t *callbacks;
} emb_type_t;

static unsigned int emb_callback_name_hash(const char *name, unsigned int size)
{
	unsigned int hash = 0, i = 0;

	while (name[i] != '\0') {
		hash += name[i] * (i+1);
		i++;
	}

	return hash % size;
}

static emb_type_t * emb_type_new(const char *name)
{
	emb_type_t *type = NULL;
	size_t len;

	type = malloc(sizeof(emb_type_t));
	len = strlen(name);
	type->name = malloc(len + 1);
	strcpy(type->name, name);

	type->callbacks = gds_hash_map_new(16,
		(gds_hash_cb) emb_callback_name_hash,
		(gds_cmpkey_cb) strcmp);
	
	return type;
}

//static void emb_type_free(emb_type_t *type)
//{
//	if (type != NULL) {
//		gds_hash_map_free(type->callbacks, free, NULL);
//		free(type->name);
//		free(type);
//	}
//}

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
		emb_types = realloc(emb_types, emb_types_size * 2);
		memset(emb_types + emb_types_size, 0, emb_types_size);
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
	gds_hash_map_t *callbacks;
	char *key;

	if (type_id >= emb_types_size || emb_types[type_id] == NULL)
		return -1;
	
	callbacks = emb_types[type_id]->callbacks;
	key = malloc(strlen(name) + 1);
	strcpy(key, name);

	return gds_hash_map_set(callbacks, key, callback, free, NULL);
}

void * emb_type_get_callback(emb_type_id_t type_id, const char *name)
{
	gds_hash_map_t *callbacks;

	if (type_id >= emb_types_size || emb_types[type_id] == NULL)
		return NULL;
	
	callbacks = emb_types[type_id]->callbacks;

	return gds_hash_map_get(callbacks, name);
}
