#include <stdio.h>
#include <libtap13/tap.h>
#include "type.h"

int main()
{
	emb_type_t *type1, *type2;
	char buffer[512];
	int i;

	plan(17);

	type1 = emb_type_get("type1");
	type2 = emb_type_get("type2");

	ok(type1 != type2);
	is(type1, emb_type_get("type1"));
	is(type2, emb_type_get("type2"));

	str_eq(emb_type_get_name(type1), "type1");
	str_eq(emb_type_get_name(type2), "type2");

	is(emb_type_get_name(NULL), NULL);

	is(emb_type_register_callback(type1, "free", free), 0);
	is(emb_type_get_callback(type1, "free"), free);
	is(emb_type_register_callback(type1, "free", main), 1);
	is(emb_type_get_callback(type1, "free"), main);
	is(emb_type_get_callback(type1, "fre"), NULL);
	is(emb_type_get_callback(type1, "freee"), NULL);
	is(emb_type_get_callback(type1, "FREE"), NULL);
	is(emb_type_get_callback(type2, "free"), NULL);
	is(emb_type_get_callback(NULL, "free"), NULL);

	is(emb_type_register_callback(NULL, "free", free), -1);

	for (i = 0; i < 512; i++) {
		sprintf(buffer, "type_%03d", i);
		emb_type_get(buffer);
	}
	pass("Generate a lot of type without segfault");

	return 0;
}
