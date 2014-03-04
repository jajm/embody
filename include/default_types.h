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

#ifndef emb_default_types_h_included
#define emb_default_types_h_included

#include <stdint.h>

int ** emb_new_int(int i);
int8_t ** emb_new_int8(int8_t i);
int16_t ** emb_new_int16(int16_t i);
int32_t ** emb_new_int32(int32_t i);
int64_t ** emb_new_int64(int64_t i);

float ** emb_new_float(float f);
double ** emb_new_double(double d);

char ** emb_new_char(char c);

#endif /* ! emb_default_types_h_included */
