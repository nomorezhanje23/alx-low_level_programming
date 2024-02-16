#include "hash_tables.h"

void add_node_at_beginning(hash_node_t **head, hash_node_t *node);

/**
 * hash_table_set - element adder to the hash table
 * @ht: hash table
 * @key: the key
 * @value: the value
 * Return: 1 if success or 0 if failure.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *ht_pair, *ht_curr, **ht_bucket;
	unsigned long int index;
	char *value_dup;

	if (!ht || !key || !(*key) || !value)
		return (0);

	index = key_index((unsigned char *)key, ht->size);
	ht_bucket = &(ht->array[index]);
	ht_curr = ht->array[index];

	value_dup = strdup(value);
	if (value_dup == NULL)
		return (0);

	while (ht_curr)
	{
		if (strcmp(ht_curr->key, key) == 0)
		{
			free(ht_curr->value);
			ht_curr->value = value_dup;
			return (1);
		}
		ht_curr = ht_curr->next;
	}

	ht_pair = malloc(sizeof(hash_node_t));
	if (ht_pair == NULL)
	{
		free(value_dup);
		return (0);
	}

	ht_pair->key = strdup(key);
	if (ht_pair->key == NULL)
	{
		free(value_dup);
		free(ht_pair);
		return (0);
	}

	ht_pair->value = value_dup;
	ht_pair->next = NULL;

	if (*ht_bucket == NULL)
	{
		*ht_bucket = ht_pair;
		return (1);
	}

	if (*ht_bucket && strcmp((*ht_bucket)->key, key) != 0)
		add_node_at_beginning(&(*ht_bucket), ht_pair);

	return (1);
}

/**
 * add_node_at_beginning - new node adder at the beginning of list
 * @head: first nodeof list
 * @node: new node
 * Return: Nothing.
 */
void add_node_at_beginning(hash_node_t **head, hash_node_t *node)
{
	if (*head == NULL)
		*head = node;

	node->next = *head;
	*head = node;
}
