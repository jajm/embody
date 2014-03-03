#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

typedef struct emb_hash_table_node_s {
	char *key;
	void *value;
	struct emb_hash_table_node_s *next;
} emb_hash_table_node_t;

static emb_hash_table_node_t * emb_hash_table_node_new(const char *key, void *value)
{
	emb_hash_table_node_t *node;

	node = malloc(sizeof(emb_hash_table_node_t));
	if (node == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		return NULL;
	}

	node->key = malloc(strlen(key) + 1);
	if (node->key == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		free(node);
		return NULL;
	}
	strcpy(node->key, key);

	node->value = value;
	node->next = NULL;

	return node;
}

static emb_hash_table_node_t * emb_hash_table_node_list_find(
	emb_hash_table_node_t *head, const char *key)
{
	emb_hash_table_node_t *found = NULL, *it = head;
	int cmp;

	while (it != NULL && (cmp = strcmp(it->key, key)) < 0) {
		it = it->next;
	}

	if (it != NULL && cmp == 0) {
		found = it;
	}

	return found;
}

static int emb_hash_table_node_list_insert(emb_hash_table_node_t **head,
	const char *key, void *value, void *free_cb)
{
	emb_hash_table_node_t *node, *it, fakehead;
	void (*free_callback)(void *ptr);
	int cmp = 1, rc = 0;

	if (head == NULL) {
		return -1;
	}

	fakehead.next = *head;
	it = &fakehead;

	while (it->next != NULL && (cmp = strcmp(it->next->key, key)) < 0) {
		it = it->next;
	}

	if (cmp == 0) {
		node = it->next;
		if (free_cb != NULL) {
			free_callback = free_cb;
			free_callback(node->value);
		}
		node->value = value;
		rc = 1;
	} else {
		node = emb_hash_table_node_new(key, value);
		node->next = it->next;
		it->next = node;
		*head = fakehead.next;
	}

	return rc;
}

struct emb_hash_table_s {
	unsigned int size;
	emb_hash_table_node_t **nodes;
};

emb_hash_table_t * emb_hash_table_new(unsigned int size)
{
	emb_hash_table_t *hash_table;

	if (size == 0) {
		return NULL;
	}

	hash_table = malloc(sizeof(emb_hash_table_t));
	if (hash_table == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		return NULL;
	}

	hash_table->nodes = calloc(size, sizeof(emb_hash_table_node_t *));
	if (hash_table->nodes == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		free(hash_table);
		return NULL;
	}

	hash_table->size = size;

	return hash_table;
}

static unsigned int emb_hash_table_hash(const char *key, unsigned int size)
{
	unsigned int hash = 5381;
	int c;

	if (!key) return 0;

	while ((c = *key++))
		hash = ((hash << 5) + hash) + c;

	return hash % size;
}

int emb_hash_table_set(emb_hash_table_t *hash_table, const char *key,
	void *value, void *free_cb)
{
	unsigned int hash;
	int rc;

	if (hash_table == NULL || key == NULL) {
		return -1;
	}

	hash = emb_hash_table_hash(key, hash_table->size);
	rc = emb_hash_table_node_list_insert(&(hash_table->nodes[hash]), key,
		value, free_cb);

	return rc;
}

void * emb_hash_table_get(emb_hash_table_t *hash_table, const char *key)
{
	emb_hash_table_node_t *node;
	unsigned int hash;
	void *value = NULL;

	if (hash_table == NULL || key == NULL) {
		return NULL;
	}

	hash = emb_hash_table_hash(key, hash_table->size);
	node = emb_hash_table_node_list_find(hash_table->nodes[hash], key);
	if (node != NULL) {
		value = node->value;
	}

	return value;
}
