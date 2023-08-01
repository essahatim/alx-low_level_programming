#include "lists.h"
/**
 * reverse_listint - Reverses a listint_t linked list.
 * @head: Ptr of the first node in the listint_t.
 * Return: Ptr of the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *rev = NULL;
	listint_t *next = NULL;

	while (*head)
	{
	next = (*head)->next;
	(*head)->next = rev;
	rev = *head;
	*head = next;
	}
	*head = rev;
	return (*head);
}
