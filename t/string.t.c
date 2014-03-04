#include <libtap13/tap.h>
#include "embody.h"

int main()
{
	char buf[] = "Hello World!\n";
	char *s;
	char **string;
	emb_type_t *string_type;

	plan(4);

	s = calloc(strlen(buf) + 1, sizeof(char));
	strcpy(s, buf);
	str_eq(s, buf);

	string_type = emb_type_get("string");
	emb_type_register_callback(string_type, "free", free);

	string = (char **) emb_new(string_type, s);
	str_eq(*string, buf);

	*string = realloc(*string, strlen(*string) * 2 + 1);
	strcat(*string, buf);
	str_eq(*string, "Hello World!\nHello World!\n");

	emb_free(string);
	is(*string, NULL);

	return 0;
}
