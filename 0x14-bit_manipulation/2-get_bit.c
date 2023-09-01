#include "main.h"
/**
 * get_bit -  Returns the value of a bit at a given index.
 * @n: Num to the index.
 * @index: Index of the bit.
 * Return: The value of the bit.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int V_bit;

	if (index > 63)
	return (-1);
	V_bit = (n >> index) & 1;
	return (V_bit);
}
