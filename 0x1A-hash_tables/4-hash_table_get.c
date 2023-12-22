#include "hash_tables.h"

/**
 * hash_table_get - Retrieves a value associated with a key.
 * @ht: The hash table to retrieve value.
 * @key: The key you are looking for.
 *
 * Return: The value associated with the element, or NULL if the key
 *         can't be found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *current;
	unsigned long int index;


	if (ht == NULL || key == NULL || ht->array == NULL ||
		strlen(key) == 0)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];
	while (current)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
