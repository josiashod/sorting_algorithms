#include "sort.h"

/**
 * swap - Swap two int.
 *
 * @a: the pointer to the first int.
 * @b: the pointer to the second int.
 */
void swap(int *a, int *b)
{
	int tmp;

	if (!a || !b)
		return;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm.
 *
 * @array: the array to sort
 * @size: the size of the given array
 *
 * Description: Uses the Knuth sequence
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;

	if (!array || size < 2)
		return;

	/* finding the largest gap */
	while (gap < (size / 3))
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j - gap] > array[j]; j -=
				     gap)
				swap(array + j, array + (j - gap));
		}
		print_array(array, size);
	}
}
