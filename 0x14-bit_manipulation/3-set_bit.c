#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at a given index.
 * @n: The number to change.
 * @index: The bit to set.
 *
 * Return: 1 on success, -1 on error.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n |= ((1UL << index);
	return (1);
}
