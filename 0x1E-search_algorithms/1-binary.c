#include "search_algos.h"

/**
 * print_array - Prints an array of integers.
 * @array: Pointer to the first element of the array to print.
 * @size: Number of elements in the array.
 */
void print_array(int *array, size_t size)
{
	size_t i;

	if (array == NULL || size == 0)
		return;

	printf("Searching in array: ");

	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * recursive_search - Searches for a value in a sorted array of integers
 *                    using the Binary search algorithm recursively.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 * Return: The index where value is located,
 *         or -1 if value is not present in array or if array is NULL.
 */
int recursive_search(int *array, size_t size, int value)
{
	size_t mid = size / 2;
	int result;

	if (array == NULL || size == 0)
		return (-1); 
	print_array(array, size);

	if (size % 2 == 0 && mid > 0)
		mid--;

	if (value == array[mid])
		return ((int)mid);

	if (value < array[mid])
		return (recursive_search(array, mid, value));

	result = recursive_search(array + mid + 1, size - mid - 1, value);

	if (result == -1)
		return (-1);

	return (result + mid + 1);
}

/**
 * binary_search - Calls recursive_search to return the index of the number.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 * Return: The index where value is located,
 *         or -1 if value is not present in array or if array is NULL.
 */
int binary_search(int *array, size_t size, int value)
{
	int index = recursive_search(array, size, value);

	if (index >= 0 && array[index] != value)
		return (-1);

	return (index);
}
