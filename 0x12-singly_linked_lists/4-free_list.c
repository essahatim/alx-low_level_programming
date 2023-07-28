#include <stdlib.h>
#include "lists.h"
/**
 * free_list - Frees a list_t list.
 * @head: The list_t list to free
 */
void free_list(list_t *head)
{
	list_t *tep;

	while (head)
	{
	tep = head->next;
	free(head->str);
	free(head);
	head = tep;
	}
}
