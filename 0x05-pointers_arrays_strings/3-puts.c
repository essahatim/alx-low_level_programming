#include<stdio.h>
/**
 * _puts -  Prints a string,
 * followed by a new line
 * @str: The string to print.
 * Return: Void.
 */
void _puts(char *str)
{
	for (; *str != '\0'; str++)
	{
	_putchar(*str);
	}
	_putchar('\n');
}
