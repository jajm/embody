#ifndef emb_type_h_included
#define emb_type_h_included

typedef unsigned short int emb_type_id_t;

emb_type_id_t
emb_type_get_id(
	const char *name
);

const char *
emb_type_get_name(
	emb_type_id_t type_id
);

int
emb_type_register_callback(
	emb_type_id_t type_id,
	const char *name,
	void *callback
);

void *
emb_type_get_callback(
	emb_type_id_t type_id,
	const char *name
);

#endif /* ! emb_type_h_included */
