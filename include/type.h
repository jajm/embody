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

#ifndef emb_type_h_included
#define emb_type_h_included

typedef struct emb_type_s emb_type_t;

/* Get type identified by string <name>.
 *
 * If type doesn't exist yet, it is created.
 *
 * Parameters
 *   name : Name of type.
 *
 * Returns
 *   Pointer to the type.
 */
emb_type_t *
emb_type_get(
	const char *name
);

/* Get name of type.
 *
 * Parameters
 *   type : Pointer to the type.
 *
 * Returns
 *   The name of type.
 */
const char *
emb_type_get_name(
	emb_type_t *type
);

/* Register a callback for a type.
 *
 * Callbacks can later be retrieved with emb_type_get_callback().
 *
 * Parameters
 *   type     : Pointer to the type.
 *   name     : Name of callback.
 *   callback : Pointer to callback.
 *
 * Returns
 *   A positive value if a callback with the same name already existed (callback
 *   was overridden).
 *   0 if callback didn't already exist and has been successfully registered.
 *   A negative value on failure.
 */
int
emb_type_register_callback(
	emb_type_t *type,
	const char *name,
	void *callback
);

/* Retrieve callback
 *
 * Parameters
 *   type : Pointer to the type.
 *   name : Name of callback.
 *
 * Returns
 *   Pointer to callback.
 *   NULL if callback doesn't exist.
 */
void *
emb_type_get_callback(
	emb_type_t *type,
	const char *name
);

#endif /* ! emb_type_h_included */
