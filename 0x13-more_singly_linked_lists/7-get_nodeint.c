#include "lists.h"
/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: First node in the listint_t.
 * @index: Index of the node to return.
 * Return: Ptr of the node we're looking for, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int a = 0;
	listint_t *tem = head;

	while (tem && a < index)
	{
	tem = tem->next;
	a++;
	}
	return (tem ? tem : NULL);
}
