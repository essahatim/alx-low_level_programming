#include "main.h"
/**
 * flip_bits - Returns the num of bits you would need to flip
 * to get from one num to another.
 * @n: First num.
 * @m: Second num.
 * Return: Num of bits to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int a;
	unsigned int current, count = 0;
	unsigned long int xor_v = n ^ m;

	for (a = 63; a >= 0; a--)
	{
		current = xor_v >> a;
		if (current & 1)
		count++;
	}
	return (count);
}
