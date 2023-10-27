#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The binary number to printed.
 */

void print_binary(unsigned long int n)
{
	int i = 63, numprint = 0, bit;

	for (; i >= 0; i--)
	{
		bit = n >> i;

		if (bit & 1)
		{
			_putchar('1');
			numprint++;
		}
		else if (numprint)
			_putchar('0');
	}
	if (!numprint)
		_putchar('0');
}
