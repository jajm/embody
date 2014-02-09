#include <limits.h>
#include <math.h>
#include <libtap13/tap.h>
#include "container.h"
#include "default_types.h"

int main()
{
	int **i;
	int8_t **i8;
	int16_t **i16;
	int32_t **i32;
	int64_t **i64;
	float **f;
	double **d;
	char **c;

	plan(8);

	i = emb_new_int(INT_MAX);
	is(**i, INT_MAX);
	emb_free(i);

	i8 = emb_new_int8(INT8_MAX);
	is(**i8, INT8_MAX);
	emb_free(i8);

	i16 = emb_new_int16(INT16_MAX);
	is(**i16, INT16_MAX);
	emb_free(i16);

	i32 = emb_new_int32(INT32_MAX);
	is(**i32, INT32_MAX);
	emb_free(i32);

	i64 = emb_new_int64(INT64_MAX);
	is(**i64, INT64_MAX);
	emb_free(i64);

	f = emb_new_float(3.141592);
	ok(fabsf(**f - 3.141592) < 0.000001);
	emb_free(f);

	d = emb_new_double(3.141592653589793);
	ok(fabs(**d - 3.141592653589793) < 0.000000000000001);
	emb_free(d);

	c = emb_new_char('A');
	is(**c, 'A');
	emb_free(c);

	return 0;
}
