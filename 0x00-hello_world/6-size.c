#include <stdio.h>

/**
 * main -Prints the size of various types a based on the 
 * computer it is compiled and run on ..
 * return: always 0.
 */

int main(void)
{
	printf("size of a char: %zu byte(s)\n", sizeof(char));
	printf("size of an int: %zu byte(s)\n", sizeof(int));
	printf("size of a lon int: %zu byte(s)\n", sizeof(long int));
	printf("size of long long int: %zu byte(s)\n" sizeof(long long int));
	printf("size of float: %zu byte(s)\n", sizeof(float));
	return (0);
}
