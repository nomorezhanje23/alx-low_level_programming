#include "hash_tables.h"

void free_bucket(hash_node_t *ht_bucket);

/**
 * hash_table_delete - hash table deleter
 * @ht: hash table
 * Return: Nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *ht_bucket;
	unsigned int u;

	if (ht == NULL)
		return;

	for (u = 0; u < ht->size; ++u)
	{
		ht_bucket = ht->array[u];
		if (ht_bucket)
			free_bucket(ht_bucket);
	}
	free(ht->array);
	free(ht);
}

/**
 * free_bucket - this frees a hash table bucket
 * @ht_bucket: linked-list to be freed
 * Return: Nothing
 */
void free_bucket(hash_node_t *ht_bucket)
{
	hash_node_t *ht_node_prev = ht_bucket;

	while (ht_bucket)
	{
		free(ht_bucket->key);
		free(ht_bucket->value);
		ht_bucket = ht_bucket->next;
		free(ht_node_prev);
		ht_node_prev = ht_bucket;
	}
}
