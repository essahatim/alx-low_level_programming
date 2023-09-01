#include "main.h"
/**
 * clear_bit - Sets the value of a bit to 0 at a given index.
 * @n: Ptr to the num to the index.
 * @index: Index of the bit to clear.
 * Return: 1 for successful, -1 for error.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > sizeof(n) * 8)
	return (-1);
	*n = (~(1L << index) & *n);
	return (1);
}
