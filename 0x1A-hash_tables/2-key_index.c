#include "hash_tables.h"

/**
 * key_index - Gives you the index of a key.
 * @key: The key of the index.
 * @size: The size of the hash table.
 *
 * Return: The index of the kye/value.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value = hash_djb2(key);

	return (hash_value % size);
}
