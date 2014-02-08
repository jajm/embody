#include <libtap13/tap.h>
#include "default_types.h"

int main()
{
	int **i;

	plan(1);

	i = emb_new_int(42);
	is(**i, 42);

	return 0;
}
