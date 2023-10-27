#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number to index.
 * @index: The bit .
 *
 * Return: The bit value or -1.
 */
int get_bit(unsigned long int n, unsigned int index)
{

	if (index > 63)
		return (-1);

	return (n >> index & 1);
}
