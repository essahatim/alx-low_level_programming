#include "main.h"
/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: Num to search.
 * @index: The index, starting from 0 of the bit you want to get.
 * Return: The value of the bit at index index or -1 if an error occured.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_v;

	if (index > 63)
	return (-1);
	bit_v = (n >> index) & 1;
	return (bit_v);
}
