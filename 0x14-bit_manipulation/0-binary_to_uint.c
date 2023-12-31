#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: The binary number of a string.
 *
 * Return: The number converts.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int number = 0;
	int i = 0;

	if (!b)
		return (0);
	for (; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		number = 2 * number + (b[i] - '0');
	}
	return (number);
}
