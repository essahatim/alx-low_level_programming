#include "lists.h"
/**
 * delete_nodeint_at_index - Deletes the node at index
 * index of a listint_t linked list.
 * @head: Ptr of the first element in the listint_t.
 * @index: Index of the node to delete.
 * Return: 1 (True), or -1 (Fauls).
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tem = *head;
	listint_t *current = NULL;
	unsigned int a = 0;

	if (*head == NULL)
	return (-1);
	if (index == 0)
	{
	*head = (*head)->next;
	free(tem);
	return (1);
	}
	while (a < index - 1)
	{
		if (!tem || !(tem->next))
		return (-1);
		tem = tem->next;
		a++;
	}
	current = tem->next;
	tem->next = current->next;
	free(current);
	return (1);
}
