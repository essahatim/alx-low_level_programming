#include "main.h"

/**
 * flip_bits - Returns the number of bits you would need to flip
 * to get from one number to another.
 * @n: First number.
 * @m: Second number.
 *
 * Return: Number bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i = 63, count = 0;
	unsigned long int current, xor = n ^ m;

	for (; i >= 0; i--)
	{
		if (current & 1UL)
			count++;
		current = xor >> i;
	}

	return (count);
}
