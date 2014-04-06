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

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "type.h"
#include "container.h"

#define container_of(ptr, type, member) \
	(type *)( (char *)ptr - offsetof(type, member) )

typedef struct {
	emb_type_t *type;
	void *data;
} emb_container_t;

void * emb_container_new(emb_type_t *type, void *data_p)
{
	emb_container_t *embc;

	embc = malloc(sizeof(emb_container_t));
	if (embc == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		return NULL;
	}

	embc->type = type;
	embc->data = data_p;

	return &(embc->data);
}

emb_type_t * emb_container_type(void *data_pp)
{
	emb_container_t *embc;

	if (data_pp == NULL) {
		return NULL;
	}

	embc = container_of(data_pp, emb_container_t, data);
	return embc->type;
}

void emb_container_free(void *data_pp)
{
	emb_container_t *embc;
	void (*free_callback)(void *) = NULL;

	if (data_pp != NULL) {
		embc = container_of(data_pp, emb_container_t, data);

		free_callback = emb_type_get_callback(embc->type, "free");
		if (free_callback) {
			free_callback(embc->data);
		}
		embc->data = NULL;
		free(embc);
	}
}

void emb_container_destroy(void *data_pp)
{
	emb_container_t *embc;

	if (data_pp != NULL) {
		embc = container_of(data_pp, emb_container_t, data);
		free(embc);
	}
}
