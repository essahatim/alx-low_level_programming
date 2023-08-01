#include "lists.h"
/**
 * sum_listint - Returns the sum of all the data (n)
 * of a listint_t linked list.
 * @head: First node in the listint_t.
 * Return: The sum.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *tem = head;

	while (tem)
	{
	sum += tem->n;
	tem = tem->next;
	}
	return (sum);
}
