#include<stdio.h>
/**
 * _strlen - That returns the length of a string.
 * @str: The string to git the length of
 * Return: The length of
 */
int _strlen(char *str)
{
	size_t length = 0;

	while (*str++)
	length++;
	return (length);
}
