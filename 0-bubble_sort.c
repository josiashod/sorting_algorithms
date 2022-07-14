#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 *
 * @array: the array that should sort
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int sorted = 0;
	int tmp;
	size_t i;

	while (!sorted)
	{
		sorted = 1;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;
				sorted = 0;
				print_array(array, size);
			}
		}
	}
}
