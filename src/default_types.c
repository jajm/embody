#include <stdlib.h>
#include "type.h"
#include "container.h"
#include "default_types.h"

#define emb_default_type_func_def(type, name) \
	static emb_type_id_t name##_type_id = -1; \
	type ** emb_new_##name(type data) \
	{ \
		type *data_p; \
		if (name##_type_id == (emb_type_id_t)-1) { \
			name##_type_id = emb_type_get_id(#name); \
			emb_type_register_callback(name##_type_id, "free", free); \
		} \
		data_p = malloc(sizeof(type)); \
		*data_p = data; \
		return (type **) emb_new(name##_type_id, data_p); \
	}

emb_default_type_func_def(int, int)
emb_default_type_func_def(int8_t, int8)
emb_default_type_func_def(int16_t, int16)
emb_default_type_func_def(int32_t, int32)
emb_default_type_func_def(int64_t, int64)

emb_default_type_func_def(double, double)
emb_default_type_func_def(float, float)

emb_default_type_func_def(char, char)
