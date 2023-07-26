#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < MIN_SIZE)
		return;

	quick_sort_array(array, START_INDEX, (int)(size - 1), size);
}

/**
 * quick_sort_array - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @low: low index
 * @high: high index
 * @size: size of the array
 */
void quick_sort_array(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (high <= low)
		return;

	partition_index = partition(array, low, high, size);

	quick_sort_array(array, low, partition_index - 1, size);
	quick_sort_array(array, partition_index + 1, high, size);
}

/**
 * partition - Lomuto partition scheme
 * @array: array to be sorted
 * @low: low index
 * @high: high index
 * @size: size of the array
 * Return: index of the pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[j], &array[i]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * swap - exchange two elements
 * @first_element: first one
 * @second_element: second one
 */
void swap(int *first_element, int *second_element)
{
	int temp = *first_element;
	*first_element = *second_element;
	*second_element = temp;
}
