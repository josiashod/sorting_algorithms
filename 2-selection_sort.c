#include "sort.h"

/**
 * swap_int - Swap two value.
 *
 * @first: the pointer to the first value.
 * @second: the pointer to the second value.
 */
void swap_int(int *first, int *second)
{
	int tmp = *second;

	*second = *first;
	*first = tmp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the selection sort algorithm.
 *
 * @array: the array to sort
 * @size: the size of the array to sort
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < (size - 1); i++)
	{
		min = array + i;

		for (j = (i + 1); j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if (array[i] != *min)
		{
			swap_int(array + i, min);
			print_array(array, size);
		}
	}
}
