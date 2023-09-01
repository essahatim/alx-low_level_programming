#include "main.h"
/**
 * binary_to_uint - Converts a binary num to unsigned int.
 * @b: A string containing the binary num.
 * Return: the converted num from of b.
 */
unsigned int binary_to_uint(const char *b)
{
	int a;
	unsigned int num = 0;

	if (!b)
	return (0);
	for (a = 0; b[a]; a++)
	{
		if (b[a] < '0' || b[a] > '1')
		return (0);
		num = 2 * num + (b[a] - '0');
	}
	return (num);

