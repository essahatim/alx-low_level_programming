#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: The number to change.
 * @index: The bit to clear.
 *
 * Return: 1 on success, -1 on failure.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n &= (~(1L << index);
	return (1);
}
