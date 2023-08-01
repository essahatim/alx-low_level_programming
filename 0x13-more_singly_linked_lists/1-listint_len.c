#include "lists.h"
/**
 * listint_len - Returns the number of elements in a linked listint_t lists.
 * @h: Linked list of type listint_t to traverse
 * Return: Numb of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t numb = 0;

	while (h)
	{
	numb++;
	h = h->next;
	}
	return (numb);
}
