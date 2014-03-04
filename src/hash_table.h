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

#ifndef emb_hash_table_h_included
#define emb_hash_table_h_included

typedef struct emb_hash_table_s emb_hash_table_t;

emb_hash_table_t *
emb_hash_table_new(
	unsigned int size
);

int
emb_hash_table_set(
	emb_hash_table_t *hash_table,
	const char *key,
	void *value,
	void *free_cb
);

void *
emb_hash_table_get(
	emb_hash_table_t *hash_table,
	const char *key
);

#endif /* ! emb_hash_table_h_included */
