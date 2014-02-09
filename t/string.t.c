#include <libtap13/tap.h>
#include "embody.h"

int main()
{
	char buf[] = "Hello World!\n";
	char *s;
	char **string;
	emb_type_id_t string_type_id;

	plan(4);

	s = calloc(strlen(buf) + 1, sizeof(char));
	strcpy(s, buf);
	str_eq(s, buf);

	string_type_id = emb_type_get_id("string");
	emb_type_register_callback(string_type_id, "free", free);

	string = (char **) emb_new(string_type_id, s);
	str_eq(*string, buf);

	*string = realloc(*string, strlen(*string) * 2 + 1);
	strcat(*string, buf);
	str_eq(*string, "Hello World!\nHello World!\n");

	emb_free(string);
	is(*string, NULL);

	return 0;
}
