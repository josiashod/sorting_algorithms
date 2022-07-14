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
	bool sorted = false;
	int tmp;
	size_t i;

	while (!sorted)
	{
		sorted = true;
		for (i = 0; i < (size - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				sorted = false;
			}
		}
	}
}
