#include "main.h"

/*
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Is the binary number of the string.
 *
 * Return: The number convert.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int number = 0;

	if (!b)
		return (0);
	for (int i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		number *= 2 + (b[i] - '0');
	}
	return (number);
}
