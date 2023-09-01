#include "main.h"
/**
 * print_binary - Prints the binary representation of a num.
 * @n: Num print in binary.
 */
void print_binary(unsigned long int n)
{
	int a, printed = 0;
	unsigned long int current;

	for (a = 63; a >= 0; a--)
	{
		current = n >> a;
		if (current & 1)
		{
		_putchar('1');
		printed++;
		}
		else if (printed)
		_putchar('0');
	}
	if (!printed)
	_putchar('0');
}
