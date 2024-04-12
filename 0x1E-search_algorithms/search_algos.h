#ifndef SEARCH_ALGOS
#define SEARCH_ALGOS

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 * struct skiplist_s - Singly linked list.
 *
 * @n: The integer.
 * @index: The index of the node in the list.
 * @next: The pointer to the next node.
 * @express: The pointer to the next node in the express lane.
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

/**
 * struct listint_s - Singly linked list.
 *
 * @n: The integer.
 * @index: The index of the node in the list.
 * @next: The pointer to the next node.
 */
typedef struct listint_s
{
	int n;
	size_t index;
	struct listint_s *next;
} listint_t;

int linear_search(int *array, size_t size, int value);
void print_array(int *array, size_t size);
int recursive_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);


#endif
