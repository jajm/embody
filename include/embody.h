#ifndef emb_embody_h_included
#define emb_embody_h_included

#include "type.h"

void **
emb_new(
	emb_type_id_t type_id,
	void *data_p
);

emb_type_id_t
emb_type_id_wrapped(
	void **data_pp
);

#define emb_type_id(data_pp) \
	emb_type_id_wrapped((void **)data_pp)

void
emb_free_wrapped(
	void **data_pp
);

#define emb_free(data_pp) \
	emb_free_wrapped((void **)data_pp)

#endif /* ! emb_embody_h_included */
