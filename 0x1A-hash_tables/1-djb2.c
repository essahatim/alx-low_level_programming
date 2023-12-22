#include "hash_tables.h"
/**
 * hash_djb2 - Implementing the djb2 algorithm.
 * @str: String of hash table.
 *
 * Return: Hash table.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	int c;
	unsigned long int hash;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}
