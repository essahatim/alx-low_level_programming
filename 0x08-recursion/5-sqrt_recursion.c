#include"main.h"
/**
 * _sqrt_recursion - returns the natural square root of a number.
 * @n: number to calculate the square root of
 * Return: The resulting square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (actual_sqrt_recursion(n, 0));
}