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
