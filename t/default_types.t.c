#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <libtap13/tap.h>
#include "container.h"
#include "default_types.h"

int main()
{
	short **short_pp;
	int **int_pp;
	long **long_pp;
	long long **longlong_pp;
	unsigned short **ushort_pp;
	unsigned int **uint_pp;
	unsigned long **ulong_pp;
	unsigned long long **ulonglong_pp;
	int8_t **int8_pp;
	int16_t **int16_pp;
	int32_t **int32_pp;
	int64_t **int64_pp;
	uint8_t **uint8_pp;
	uint16_t **uint16_pp;
	uint32_t **uint32_pp;
	uint64_t **uint64_pp;
	float **float_pp;
	double **double_pp;
	long double **longdouble_pp;
	char **char_pp;
	signed char **schar_pp;
	unsigned char **uchar_pp;
	_Bool **bool_pp;

	plan(23);

	short_pp = emb_new_short(SHRT_MAX);
	is(**short_pp, SHRT_MAX, "short");
	emb_free(short_pp);

	int_pp = emb_new_int(INT_MAX);
	is(**int_pp, INT_MAX, "int");
	emb_free(int_pp);

	long_pp = emb_new_long(LONG_MAX);
	is(**long_pp, LONG_MAX, "long");
	emb_free(long_pp);

	longlong_pp = emb_new_longlong(LLONG_MAX);
	is(**longlong_pp, LLONG_MAX, "long long");
	emb_free(longlong_pp);

	ushort_pp = emb_new_ushort(USHRT_MAX);
	is(**ushort_pp, USHRT_MAX, "unsigned short");
	emb_free(ushort_pp);

	uint_pp = emb_new_uint(UINT_MAX);
	is(**uint_pp, UINT_MAX, "unsigned int");
	emb_free(uint_pp);

	ulong_pp = emb_new_ulong(ULONG_MAX);
	is(**ulong_pp, ULONG_MAX, "unsigned long");
	emb_free(ulong_pp);

	ulonglong_pp = emb_new_ulonglong(ULLONG_MAX);
	is(**ulonglong_pp, ULLONG_MAX, "unsigned long long");
	emb_free(ulonglong_pp);

	int8_pp = emb_new_int8(INT8_MAX);
	is(**int8_pp, INT8_MAX, "int8_t");
	emb_free(int8_pp);

	int16_pp = emb_new_int16(INT16_MAX);
	is(**int16_pp, INT16_MAX, "int16_t");
	emb_free(int16_pp);

	int32_pp = emb_new_int32(INT32_MAX);
	is(**int32_pp, INT32_MAX, "int32_t");
	emb_free(int32_pp);

	int64_pp = emb_new_int64(INT64_MAX);
	is(**int64_pp, INT64_MAX, "int64_t");
	emb_free(int64_pp);

	uint8_pp = emb_new_uint8(UINT8_MAX);
	is(**uint8_pp, UINT8_MAX, "uint8_t");
	emb_free(uint8_pp);

	uint16_pp = emb_new_uint16(UINT16_MAX);
	is(**uint16_pp, UINT16_MAX, "uint16_t");
	emb_free(uint16_pp);

	uint32_pp = emb_new_uint32(UINT32_MAX);
	is(**uint32_pp, UINT32_MAX, "uint32_t");
	emb_free(uint32_pp);

	uint64_pp = emb_new_uint64(UINT64_MAX);
	is(**uint64_pp, UINT64_MAX, "uint64_t");
	emb_free(uint64_pp);

	float_pp = emb_new_float(FLT_MAX);
	ok(fabsf(**float_pp - FLT_MAX) < FLT_EPSILON, "float");
	emb_free(float_pp);

	double_pp = emb_new_double(DBL_MAX);
	ok(fabs(**double_pp - DBL_MAX) < DBL_EPSILON, "double");
	emb_free(double_pp);

	longdouble_pp = emb_new_longdouble(LDBL_MAX);
	ok(fabs(**longdouble_pp - LDBL_MAX) < LDBL_EPSILON, "long double");
	emb_free(longdouble_pp);

	char_pp = emb_new_char(CHAR_MAX);
	is(**char_pp, CHAR_MAX, "char");
	emb_free(char_pp);

	schar_pp = emb_new_schar(SCHAR_MAX);
	is(**schar_pp, SCHAR_MAX, "signed char");
	emb_free(schar_pp);

	uchar_pp = emb_new_uchar(UCHAR_MAX);
	is(**uchar_pp, UCHAR_MAX, "unsigned char");
	emb_free(uchar_pp);

	bool_pp = emb_new_bool(true);
	is(**bool_pp, true, "_Bool");
	emb_free(bool_pp);

	return 0;
}
