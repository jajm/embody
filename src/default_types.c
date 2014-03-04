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
#include "type.h"
#include "container.h"
#include "default_types.h"

#define emb_default_type_func_def(type, name) \
	static emb_type_t *name##_type = NULL; \
	type ** emb_new_##name(type data) \
	{ \
		type *data_p; \
		if (name##_type == NULL) { \
			name##_type = emb_type_get(#name); \
			emb_type_register_callback(name##_type, "free", free); \
		} \
		data_p = malloc(sizeof(type)); \
		*data_p = data; \
		return (type **) emb_new(name##_type, data_p); \
	}

emb_default_type_func_def(int, int)
emb_default_type_func_def(int8_t, int8)
emb_default_type_func_def(int16_t, int16)
emb_default_type_func_def(int32_t, int32)
emb_default_type_func_def(int64_t, int64)

emb_default_type_func_def(double, double)
emb_default_type_func_def(float, float)

emb_default_type_func_def(char, char)
