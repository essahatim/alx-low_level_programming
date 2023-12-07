#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node of a dlistint_t.
 * @head: A pointer to the head of the dlistint_t.
 * @index: The index of the node delete.
 *
 * Return: 1 on (succeed), -1 on (failed).
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *tmp;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);
	current = *head;
	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}
	while (current != NULL && i < index - 1)
	{
		current = current->next;
		i++;
	}
	if (current == NULL || current->next == NULL)
		return (-1);
	tmp = current->next;
	current->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = current;
	free(tmp);
	return (1);
}
