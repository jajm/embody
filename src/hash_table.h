#ifndef emb_hash_table_h_included
#define emb_hash_table_h_included

typedef struct emb_hash_table_s emb_hash_table_t;

emb_hash_table_t *
emb_hash_table_new(
	unsigned int size
);

int
emb_hash_table_set(
	emb_hash_table_t *hash_table,
	const char *key,
	void *value,
	void *free_cb
);

void *
emb_hash_table_get(
	emb_hash_table_t *hash_table,
	const char *key
);

#endif /* ! emb_hash_table_h_included */
