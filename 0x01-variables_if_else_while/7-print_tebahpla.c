#include<stdlib.h>
#include<stdio.h>
#include<time.h>
/**
 * main - Prints the lowercase alphabet in reverse.
 *
 * Return: Always 0 (success)
 */
int main(void)
{
	char c = 'z'

	while (c  >= 'a')
	{
		putchar(c);
		c--;
	}
	putchar('\n');
	return (0);
}
