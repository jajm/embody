#include <libtap13/tap.h>
#include "container.h"

int main()
{
	int *integer_p;
	int **integer_pp;

	plan(8);

	integer_p = malloc(sizeof(int));
	*integer_p = 42;

	emb_type_id_t integer_type_id = emb_type_get_id("integer");
	emb_type_register_callback(integer_type_id, "free", free);
	integer_pp = (int **)emb_new(integer_type_id, integer_p);

	isnt(integer_pp, NULL);
	is(*integer_pp, integer_p);
	is(**integer_pp, 42);

	*integer_p = 43;
	is(**integer_pp, 43);

	is(emb_type_id(integer_pp), integer_type_id);
	str_eq(emb_type(integer_pp), "integer");

	emb_free(integer_pp);
	is(*integer_pp, NULL);

	integer_pp = (int **) emb_new(integer_type_id, malloc(sizeof(int)));
	**integer_pp = 21;
	emb_free(integer_pp);
	is(*integer_pp, NULL);

	return 0;
}