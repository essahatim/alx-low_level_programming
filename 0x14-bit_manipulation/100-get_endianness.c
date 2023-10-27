#include "main.h"

/**
 * get_endianness - Checks the endianness.
 * Return: 0 if big, 1 if little
 */
int get_endianness(void)
{
	unsigned long int i = 1;

	return (*(char *) &i);
}
