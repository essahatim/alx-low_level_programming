#include "main.h"
/**
 * get_endianness -  checks the endianness.
 * Return: 0 if big, 1 if small.
 */
int get_endianness(void)
{
	unsigned int n = 1;
	char *c = (char *) &n;
	
	return (*c);
}
