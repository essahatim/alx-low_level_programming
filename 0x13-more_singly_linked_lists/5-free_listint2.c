#include "lists.h"
/**
 * free_listint2 - Frees a listint_t list.
 * @head: Ptr of the listint_t to be freed.
 */
void free_listint2(listint_t **head)
{
	listint_t *tem;

	if (head == NULL)
	return;
	while (*head)
	{
	tem = (*head)->next;
	free(*head);
	*head = tem;
	}
	*head = NULL;
}
