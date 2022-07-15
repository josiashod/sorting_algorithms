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

	if (!a || *b)
		return;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - Lomuto Partition array and get the pivot
 *
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The starting index of the subset to order.
 * @high: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
size_t partition(int *array, size_t size, int low, int high)
{
	int *pivot, above, below;

	pivot = array + high;
	for (above = below = low; below < high; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition to order.
 * @high: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void sort(int *array, size_t size, int low, int high)
{
	int part;

	if (high - low > 0)
	{
		part = partition(array, size, low, high);
		sort(array, size, low, part - 1);
		sort(array, size, part + 1, high);
	}
}


/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 *
 * @array: the array to sort
 * @size: the size of the given array
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, size, 0, size - 1);
}
