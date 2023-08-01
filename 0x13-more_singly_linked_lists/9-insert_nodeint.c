#include "lists.h"
/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 * @head: Ptr of the first node.
 * @idx: Index the new node.
 * @n: Data to insert in the new node
 * Return: Ptr of the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int a;
	listint_t *new;
	listint_t *tem = *head;

	new = malloc(sizeof(listint_t));
	if (!new || !head)
	return (NULL);
	new->n = n;
	new->next = NULL;
	if (idx == 0)
	{
	new->next = *head;
	*head = new;
	return (new);
	}
	for (a = 0; tem && a < idx; a++)
	{
		if (a == idx - 1)
		{
		new->next = tem->next;
		tem->next = new;
		return (new);
		}
		else
		tem = tem->next;
	}
	return (NULL);
}
