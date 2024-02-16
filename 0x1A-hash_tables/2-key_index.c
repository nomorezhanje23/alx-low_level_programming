#include "hash_tables.h"

/**
 * key_index - index for key in the array
 * @key: the key
 * @size: the size
 * Return: index of the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash, index;

	hash = hash_djb2(key);
	index = hash % size;

	return (index);
}
