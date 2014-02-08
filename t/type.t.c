#include <stdio.h>
#include <libtap13/tap.h>
#include "type.h"

int main()
{
	emb_type_id_t type1_id, type2_id;
	char buffer[512];
	int i;

	plan(17);

	type1_id = emb_type_get_id("type1");
	type2_id = emb_type_get_id("type2");

	ok(type1_id != type2_id);
	is(type1_id, emb_type_get_id("type1"));
	is(type2_id, emb_type_get_id("type2"));

	str_eq(emb_type_get_name(type1_id), "type1");
	str_eq(emb_type_get_name(type2_id), "type2");

	is(emb_type_get_name((emb_type_id_t)-1), NULL);

	is(emb_type_register_callback(type1_id, "free", free), 0);
	is(emb_type_get_callback(type1_id, "free"), free);
	is(emb_type_register_callback(type1_id, "free", main), 1);
	is(emb_type_get_callback(type1_id, "free"), main);
	is(emb_type_get_callback(type1_id, "fre"), NULL);
	is(emb_type_get_callback(type1_id, "freee"), NULL);
	is(emb_type_get_callback(type1_id, "FREE"), NULL);
	is(emb_type_get_callback(type2_id, "free"), NULL);
	is(emb_type_get_callback((emb_type_id_t)-1, "free"), NULL);

	is(emb_type_register_callback((emb_type_id_t)-1, "free", free), -1);

	for (i = 0; i < 512; i++) {
		sprintf(buffer, "type_%03d", i);
		emb_type_get_id(buffer);
	}
	pass("Generate a lot of type id without segfault");

	return 0;
}
