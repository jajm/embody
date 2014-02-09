#ifndef emb_container_h_included
#define emb_container_h_included

#include "type.h"

void **
emb_container_new(
	emb_type_id_t type_id,
	void *data_p
);

#define emb_new(type_id, data_p) \
	emb_container_new(type_id, data_p)

emb_type_id_t
emb_container_type_id(
	void **data_pp
);

#define emb_type_id(data_pp) \
	emb_container_type_id((void **)data_pp)

#define emb_type(data_pp) \
	emb_type_get_name(emb_type_id(data_pp))

void
emb_container_free(
	void **data_pp
);

#define emb_free(data_pp) \
	emb_container_free((void **)data_pp)

#endif /* ! emb_container_h_included */
