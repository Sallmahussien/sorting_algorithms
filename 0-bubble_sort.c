#include "sort.h"

/**
 * bubble_sort - algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool is_swapped = false;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				is_swapped = true;
				print_array(array, size);
			}
		}
		if (!is_swapped)
			break;
	}
}
