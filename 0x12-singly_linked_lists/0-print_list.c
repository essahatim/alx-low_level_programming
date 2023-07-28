#include <stdio.h>
#include "lists.h"
/**
 * print_list - Prints all the elements of a list_t list .
 * @h: The pointer to the list_t
 * Return: The num of nodes
 */
size_t print_list(const list_t *h)
{
	size_t a = 0;

	while (h)
	{
	if (!h->str)
	printf("[0] (nil)\n");
	else
		printf("[%u] %a\n", h->len, h->str);
	h = h->next;
	a++;
	}
	return (a);
}
