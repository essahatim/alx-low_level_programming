#include "lists.h"
/**
 * pop_listint - Deletes the head node of a listint_t linked list,
 * and returns the head node’s data (n).
 * @head: Ptr of the first element in the listint_t.
 * Return: The data inside the elements that was deleted,
 * or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
	listint_t *tem;
	int numb;

	if (!head || !*head)
	return (0);
	numb = (*head)->n;
	tem = (*head)->next;
	free(*head);
	*head = tem;
	return (numb);
}
