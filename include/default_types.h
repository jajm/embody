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

#include <stdbool.h>
#include <stdint.h>

/*
 * All functions below register a type whose name is the last part of the
 * function name (e.g. emb_new_short() registers type "short") and register
 * free() as the "free" callback for it.
 */

/* Basic integer types */
short ** emb_new_short(short i);
int ** emb_new_int(int i);
long ** emb_new_long(long i);
long long ** emb_new_longlong(long long i);

#define emb_new_ushort(i) \
	(unsigned short **) emb_new_short( (unsigned short) i )
#define emb_new_uint(i) \
	(unsigned int **) emb_new_int( (unsigned int) i )
#define emb_new_ulong(i) \
	(unsigned long **) emb_new_long( (unsigned long) i )
#define emb_new_ulonglong(i) \
	(unsigned long long **) emb_new_longlong( (unsigned long long) i )

/* Fixed-width integer types */
int8_t ** emb_new_int8(int8_t i);
int16_t ** emb_new_int16(int16_t i);
int32_t ** emb_new_int32(int32_t i);
int64_t ** emb_new_int64(int64_t i);

#define emb_new_uint8(i) \
	(uint8_t **) emb_new_int8( (uint8_t) i )
#define emb_new_uint16(i) \
	(uint16_t **) emb_new_int16( (uint16_t) i )
#define emb_new_uint32(i) \
	(uint32_t **) emb_new_int32( (uint32_t) i )
#define emb_new_uint64(i) \
	(uint64_t **) emb_new_int64( (uint64_t) i )

/* Floating point types */
float ** emb_new_float(float f);
double ** emb_new_double(double d);
long double ** emb_new_longdouble(long double d);

/* Char types */
char ** emb_new_char(char c);

#define emb_new_schar(c) \
	(signed char **) emb_new_char( (signed char) c )
#define emb_new_uchar(c) \
	(unsigned char **) emb_new_char( (unsigned char) c )

/* Boolean type */
_Bool ** emb_new_bool(_Bool b);

#endif /* ! emb_default_types_h_included */
