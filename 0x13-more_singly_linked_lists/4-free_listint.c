#include "lists.h"
/**
 * free_listint - Frees a listint_t list.
 * @head: List listint_t  to be freed.
 */
void free_listint(listint_t *head)
{
	listint_t *tem;

	while (head)
	{
	tem = head->next;
	free(head);
	head = tem;
	}
}
