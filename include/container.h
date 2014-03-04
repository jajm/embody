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

#ifndef emb_container_h_included
#define emb_container_h_included

#include "type.h"

/* How to use containers.
 *
 * Containers allow to store a type identifier besides your data.
 * Once you have created a container, you can access and modify your data as if
 * it was not contained, and you can retrieve its type.
 *
 * Example:
 *
 *   emb_type_t *string_type = emb_type_get("string");
 *   char *string = "Hello, world!\n";
 *   char **string_p = emb_container_new(string_type, string);
 *
 *   printf("%s", *string_p);
 *   printf("type: %s\n", emb_type_get_name(emb_container_type(string_p)));
 *
 *   // You can still modify your data
 *   *string_p = realloc(*string_p, 80);
 *   *string_p = strcat(*string_p, "foo bar baz\n");
 *
 *   // Don't forget to free
 *   emb_type_register_callback(string_type, "free", free);
 *   emb_container_free(string_p);
 */

/* Create a new container
 *
 * Parameters
 *   type   : Pointer to the type.
 *   data_p : Pointer to data.
 *
 * Returns
 *   Pointer to pointer to the data.
 *   You will need this pointer to use the functions below.
 */
void **
emb_container_new(
	emb_type_t *type,
	void *data_p
);

/* Create a new container using type name.
 *
 * Parameters
 *   type_name : Name of type (const char *)
 *   data_p    : Pointer to data (void *)
 *
 * Returns
 *   Pointer to pointer to the data (void **)
 *   NULL on failure
 */
#define emb_new(type_name, data_p) \
	emb_container_new(emb_type_get(type_name), data_p)

/* Retrieves type from data pointer
 *
 * Parameters
 *   data_pp : Pointer to pointer to data, as returned by emb_container_new().
 *
 * Returns
 *   Pointer to the type.
 */
emb_type_t *
emb_container_type(
	void **data_pp
);

/* Alias for emb_container_type_id(). */
#define emb_type(data_pp) \
	emb_container_type((void **)data_pp)

/* Retrieves type name from data pointer.
 *
 * Parameters
 *   data_pp : Pointer to pointer to data, as returned by emb_container_new().
 *
 * Returns
 *   Name of type.
 */
#define emb_type_name(data_pp) \
	emb_type_get_name(emb_type(data_pp))

/* Destroy container and contained data.
 *
 * It frees contained data only if a registered callback named "free" exist for
 * this data type. Otherwise you have to free memory yourself.
 *
 * Parameters
 *   data_pp : Pointer to pointer to data, as returned by emb_container_new().
 */
void
emb_container_free(
	void **data_pp
);

/* Alias for emb_container_free(). */
#define emb_free(data_pp) \
	emb_container_free((void **)data_pp)

#endif /* ! emb_container_h_included */
