#include "lists.h"
/**
 * print_listint - Prints all the elements of a listint_t list.
 * @h: Linked list of type listint_t to print.
 * Return: Nums of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t numbs = 0;

	while (h)
	{
	printf("%d\n", h->n);
	numbs++;
	h = h->next;
	}
	return (numbs);
}
