#include "hash_tables.h"
/**
 * shash_table_create - Create the s hash table.
 * @size: The size of s hash table.
 *
 * Return: The pointer of the new s hash table, or NULL.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *sht;
	unsigned long int i = 0;

	sht = malloc(sizeof(shash_table_t));
	if (sht == NULL)
	return (NULL);

	sht->size = size;
	sht->array = malloc(sizeof(shash_node_t *) * size);
	if (sht->array == NULL)
	{
		free(sht);
		return (NULL);
	}

	for (; i < size; i++)
		sht->array[i] = NULL;

	sht->shead = NULL;
	sht->stail = NULL;

	return (sht);
}

/**
* create_shash_node - Create a s new node and add it to the liste.
* @key: The kye of the s node.
* @value: The value of the s node.
*
* Return: The shn, or Null.
*/
shash_node_t *create_shash_node(const char *key, const char *value)
{
	shash_node_t *s_new_node;

	s_new_node = malloc(sizeof(shash_node_t));
	if (s_new_node == NULL)
		return (NULL);
	s_new_node->key = strdup(key);
	if (s_new_node->key == NULL)
	{
		free(s_new_node);
		return (NULL);
	}
	s_new_node->value = strdup(value);
	if (s_new_node->value == NULL)
	{
		free(s_new_node->key);
		free(s_new_node);
		return (NULL);
	}
	s_new_node->next = s_new_node->snext = s_new_node->sprev = NULL;
	return (s_new_node);
}

/**
 * add_sorted_node - Inserts a s new node .
 * @ht: The shash table.
 * @key: The key for the new node.
 * @s_node: The new node to insert.
 */
void add_sorted_node(shash_table_t *ht, const char *key, shash_node_t *s_node)
{
	shash_node_t *current;

	if (ht == NULL || s_node == NULL)
		return;
	if (ht->shead == NULL || strcmp(key, ht->shead->key) < 0)
	{
		s_node->snext = ht->shead;
		s_node->sprev = NULL;
		if (ht->shead != NULL)
			ht->shead->sprev = s_node;
		ht->shead = s_node;
		if (ht->stail == NULL)
			ht->stail = s_node;
	}
	else
	{
		current = ht->shead;
		while (current->snext != NULL && strcmp(key, current->snext->key) > 0)
			current = current->snext;
		s_node->snext = current->snext;
		s_node->sprev = current;
		if (current->snext != NULL)
			current->snext->sprev = s_node;
		current->snext = s_node;
		if (s_node->snext == NULL)
			ht->stail = s_node;
	}
}

/**
 * shash_table_set - Adds an element to the hash table.
 * @ht: The hash table to add the key/value.
 * @key: The key of data.
 * @value: The value associated with the key.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 *
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *s_new_node, *current;

	if (ht == NULL || key == NULL || strlen(key) == 0 ||
		ht->array == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			if (current->value == NULL)
				return (0);
			return (1);
		}
		current = current->next;
	}
	s_new_node = create_shash_node(key, value);
	if (s_new_node == NULL)
		return (0);
	s_new_node->next = ht->array[index];
	ht->array[index] = s_new_node;
	insert_sorted_node(ht, s_new_node)
	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key.
 * @ht: The hash table to retrieve value.
 * @key: The key you are looking for.
 *
 * Return: The value associated with the element, or NULL if the key
 *         can't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *current;
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

/**
 * shash_table_print - Prints a s hash table.
 * @ht: The hash table to print.
 */
void shash_table_print(const shash_table_t *ht)
{
	char printed = 0;
	shash_node_t *current;

	if (ht == NULL || ht->array == NULL)
		return;

	printf("{");
	current = ht->shead;

	while (current != NULL)
	{
		if (printed == 1)
			printf(", ");
		printf("'%s': '%s'", current->key, current->value);
		printed = 1;
		current = current->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a s hash table in reverse.
 * @ht: The hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	char printed = 0;
	shash_node_t *current;

	if (ht == NULL || ht->array == NULL)
		return;

	printf("{");
	current = ht->stail;

	while (current != NULL)
	{
		if (printed == 1)
			printf(", ");
		printf("'%s': '%s'", current->key, current->value);
		printed = 1;
		current = current->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a s hash table.
 * @ht: The hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i = 0;
	shash_node_t *current, *tmp;

	if (ht == NULL)
		return;

	for (; i < ht->size; i++)
	{
		current = ht->array[i];
		while (current != NULL)
		{
			tmp = current;
			current = current->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
	}
	free(ht->array);
	free(ht);
}
