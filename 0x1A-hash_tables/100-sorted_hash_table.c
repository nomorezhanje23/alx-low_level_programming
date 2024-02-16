#include "hash_tables.h"

/**
 * shash_table_create -  sorted hash table creator
 * @size: hash table size
 * Return: Pointer to the new table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *sht;
	unsigned long int i;

	sht = malloc(sizeof(shash_table_t));
	if (sht == NULL)
		return (NULL);
	sht->size = size;
	sht->shead = NULL;
	sht->stail = NULL;

	sht->array = malloc(sizeof(shash_node_t *) * size);
	if (sht->array == NULL)
	{
		free(sht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		sht->array[i] = NULL;

	return (sht);
}

/**
 * make_shash_node - sorted hash table node creator
 * @key: data key
 * @value: the key value
 * Return: new node pointer, or NULL on failure.
 */
shash_node_t *make_shash_node(const char *key, const char *value)
{
	shash_node_t *shn;

	shn = malloc(sizeof(shash_node_t));
	if (shn == NULL)
		return (NULL);


	shn->key = strdup(key);
	if (shn->key == NULL)
	{
		free(shn);
		return (NULL);
	}

	shn->value = strdup(value);
	if (shn->value == NULL)
	{
		free(shn->key);
		free(shn);
		return (NULL);
	}

	shn->next = shn->snext = shn->sprev = NULL;
	return (shn);
}

/**
 * add_to_sorted_list - linked list node adder
 * @table: sorted hash table
 * @node: node to add
 * Return: void
 */
void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *sht_curr;

	if (table->shead == NULL && table->stail == NULL)
	{
		table->shead = table->stail = node;
		return;
	}

	sht_curr = table->shead;
	while (sht_curr != NULL)
	{
		if (strcmp(node->key, sht_curr->key) < 0)
		{
			node->snext = sht_curr;
			node->sprev = sht_curr->sprev;
			sht_curr->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		}
		sht_curr = sht_curr->snext;
	}

	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}

/**
 * shash_table_set - value key in the hash table assigner
 * @ht: hash table
 * @key: key
 * @value: value to add
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	char *new_value;
	shash_node_t *shn, *sht_curr;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
		key == NULL || strlen(key) == 0 || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	sht_curr = ht->array[index];

	while (sht_curr != NULL)
	{
		if (strcmp(sht_curr->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(sht_curr->value);
			sht_curr->value = new_value;
			return (1);
		}
		sht_curr = sht_curr->next;
	}

	shn = make_shash_node(key, value);
	if (shn == NULL)
		return (0);
	shn->next = ht->array[index];
	ht->array[index] = shn;
	add_to_sorted_list(ht, shn);
	return (1);
}

/**
 * shash_table_get - hash table value retriever
 * @ht: hash table
 * @key: key value
 * Return: value key, or NULL on failure
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *sht_curr;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
		key == NULL || strlen(key) == 0)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	sht_curr = ht->array[index];

	while (sht_curr != NULL)
	{
		if (strcmp(sht_curr->key, key) == 0)
			return (sht_curr->value);
		sht_curr = sht_curr->next;
	}
	return (NULL);
}


/**
 * shash_table_print - dispalays sorted hash table
 * @ht: hash table
 * Return: Nothing
 */
void shash_table_print(const shash_table_t *ht)
{
		shash_node_t *sht_curr;
		char first_printed = 0;

		if (ht == NULL || ht->array == NULL)
			return;

		putchar('{');

		sht_curr = ht->shead;
		while (sht_curr != NULL)
		{
			if (first_printed == 1)
				printf(", ");
			printf("'%s': '%s'", sht_curr->key, sht_curr->value);
			first_printed = 1;
			sht_curr = sht_curr->snext;
		}

		printf("}\n");
}


/**
 * shash_table_print_rev - displays sorted harsh table in reverse order
 * @ht: hash table
 * Return: Nothing
 */
void shash_table_print_rev(const shash_table_t *ht)
{
		shash_node_t *sht_curr;
		char first_printed = 0;

		if (ht == NULL || ht->array == NULL)
			return;

		putchar('{');

		sht_curr = ht->stail;
		while (sht_curr != NULL)
		{
			if (first_printed == 1)
				printf(", ");
			printf("'%s': '%s'", sht_curr->key, sht_curr->value);
			first_printed = 1;
			sht_curr = sht_curr->sprev;
		}

		printf("}\n");
}


/**
 * shash_table_delete - sorted hash table deleter
 * @ht: hash table
 * Return: Nothing
 */
void shash_table_delete(shash_table_t *ht)
{
		unsigned long int n;
		shash_node_t *next;

		if (ht == NULL || ht->array == NULL || ht->size == 0)
			return;

		for (n = 0; n < ht->size; ++n)
		{
			while (ht->array[n])
			{
				next = ht->array[n]->next;
				free(ht->array[n]->key);
				free(ht->array[n]->value);
				free(ht->array[n]);
				ht->array[n] = next;
			}
		}
		free(ht->array);
		ht->array = NULL;
		ht->shead = ht->stail = NULL;
		ht->size = 0;
		free(ht);
}
