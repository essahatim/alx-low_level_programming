#include <stdio.h>
void first(void) __attribute__ ((constructor));

/**
 * first - Prints You're beat! and yet, you must allow,\nI bore my house upon my back!\n
 * before the main
 * Function is executed
 */
void first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
