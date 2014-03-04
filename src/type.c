/*
 * Copyright 2014 Julian Maurice
 *
 * This file is part of embody
 *
 * embody is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * embody is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with embody.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "type.h"

struct emb_type_s {
	char *name;
	emb_hash_table_t *callbacks;
};

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

static emb_hash_table_t *emb_types = NULL;

static void emb_types_initialize(void)
{
	if (emb_types == NULL) {
		emb_types = emb_hash_table_new(256);
	}
}

emb_type_t * emb_type_get(const char *name)
{
	emb_type_t *type;

	emb_types_initialize();

	type = emb_hash_table_get(emb_types, name);
	if (type == NULL) {
		type = emb_type_new(name);
		emb_hash_table_set(emb_types, name, type, NULL);
	}

	return type;
}

const char * emb_type_get_name(emb_type_t *type)
{
	if (type == NULL) {
		return NULL;
	}

	return type->name;
}

int emb_type_register_callback(emb_type_t *type, const char *name,
	void *callback)
{
	if (type == NULL) {
		return -1;
	}

	return emb_hash_table_set(type->callbacks, name, callback, NULL);
}

void * emb_type_get_callback(emb_type_t *type, const char *name)
{
	if (type == NULL) {
		return NULL;
	}

	return emb_hash_table_get(type->callbacks, name);
}
