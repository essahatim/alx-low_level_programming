#include "main.h"
/**
 * binary_to_uint - Converts a binary num to an unsigned int.
 * @b: Pointing to a string of 0 and 1 chars.
 * Return: The converted num.
 */
unsigned int binary_to_uint(const char *b)
{
	int a;
	unsigned int dec_v = 0;

	if (!b)
	return (0);
	for (a = 0; b[a]; a++)
	{
	if (b[a] < '0' || b[a] > '1')
	return (0);
	dec_v = 2 * dec_v + (b[a] - '0');
	}
	return (dec_v);
}
