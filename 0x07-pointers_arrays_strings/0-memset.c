#include"main.h"
/**
 * _memset - Fills memory with a constant byte
 * @n: bytes of the memory area pointed
 * @s: staring address of memory
 * @b: the desired value
 * Return: changed arrya with new value for n bytes
 */
char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
