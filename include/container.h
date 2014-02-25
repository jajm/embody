#ifndef emb_container_h_included
#define emb_container_h_included

#include "type.h"

/* How to use containers.
 *
 * Containers allow to store a type identifier besides your data.
 * Once you have created a container, you can access and modify your data as if
 * it was not contained, and you can retrieve its type.
 *
 * Example:
 *
 *   emb_type_id_t string_type_id = emb_type_get_id("string");
 *   char *string = "Hello, world!\n";
 *   char **string_p = emb_container_new(string_type_id, string);
 *
 *   printf("%s", *string_p);
 *   printf("type id: %s\n", emb_container_type_id(string_p));
 *
 *   // You can still modify your data
 *   *string_p = realloc(*string_p, 80);
 *   *string_p = strcat(*string_p, "foo bar baz\n");
 *
 *   // Don't forget to free
 *   emb_type_register_callback(string_type_id, "free", free);
 *   emb_container_free(string_p);
 */

/* Create a new container
 *
 * Parameters
 *   type_id : Integer identifier of type.
 *   data_p  : Pointer to data.
 *
 * Returns
 *   Pointer to pointer to the data.
 *   You will need this pointer to use the functions below.
 */
void **
emb_container_new(
	emb_type_id_t type_id,
	void *data_p
);

/* Alias for emb_container_new(). */
#define emb_new(type_id, data_p) \
	emb_container_new(type_id, data_p)

/* Retrieves type identifier from data pointer
 *
 * Parameters
 *   data_pp : Pointer to pointer to data, as returned by emb_container_new().
 *
 * Returns
 *   Integer identifier of type.
 */
emb_type_id_t
emb_container_type_id(
	void **data_pp
);

/* Alias for emb_container_type_id(). */
#define emb_type_id(data_pp) \
	emb_container_type_id((void **)data_pp)

/* Retrieves type name from data pointer.
 *
 * Parameters
 *   data_pp : Pointer to pointer to data, as returned by emb_container_new().
 *
 * Returns
 *   Name of type.
 */
#define emb_type(data_pp) \
	emb_type_get_name(emb_type_id(data_pp))

/* Destroy container and contained data.
 *
 * It frees contained data only if a registered callback named "free" exist for
 * this data type. Otherwise you have to free memory yourself.
 *
 * Parameters
 *   data_pp : Pointer to pointer to data, as returned by emb_container_new().
 */
void
emb_container_free(
	void **data_pp
);

/* Alias for emb_container_free(). */
#define emb_free(data_pp) \
	emb_container_free((void **)data_pp)

#endif /* ! emb_container_h_included */
