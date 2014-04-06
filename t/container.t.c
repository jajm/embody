#include <libtap13/tap.h>
#include "container.h"

int main()
{
	int *integer_p;
	int **integer_pp;

	plan(7);

	integer_p = malloc(sizeof(int));
	*integer_p = 42;

	emb_type_t *integer_type = emb_type_get("integer");
	emb_type_register_callback(integer_type, "free", free);
	integer_pp = emb_new("integer", integer_p);

	isnt(integer_pp, NULL);
	is(*integer_pp, integer_p);
	is(**integer_pp, 42);

	*integer_p = 43;
	is(**integer_pp, 43);

	is(emb_type(integer_pp), integer_type);
	str_eq(emb_type_name(integer_pp), "integer");

	emb_free(integer_pp);

	integer_pp = emb_new("integer", malloc(sizeof(int)));
	**integer_pp = 21;
	emb_free(integer_pp);

	emb_free(NULL);
	pass("emb_free(NULL) does not fail");

	integer_pp = emb_new("integer", malloc(sizeof(int)));
	integer_p = *integer_pp;
	emb_destroy(integer_pp);
	free(integer_p);

	return 0;
}
