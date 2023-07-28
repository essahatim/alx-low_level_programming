#include <stdlib.h>
#include "lists.h"
/**
 * list_len - Returns the num of elements in a linked list_t list.
 * @h: The pointer to the list_t.
 * Return: Num of elements in h
 */
size_t list_len(const list_t *h)
{
	size_t x = 0;

	while (h)
	{
	x++;
	h = h->next;
	}
	return (x);
}
