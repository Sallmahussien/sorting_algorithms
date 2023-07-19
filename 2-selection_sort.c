#include "sort.h"

/**
 * selection_sort - algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t curr_idx, min_idx;

	for (curr_idx = 0; curr_idx < size - 1; curr_idx++)
	{
		min_idx = find_minimum_index(array, curr_idx, size);

		if (min_idx != curr_idx)
		{
			swap(&array[curr_idx], &array[min_idx]);
			print_array(array, size);
		}
	}
}

/**
 * find_minimum_index - find minimum
 * @array: array to be sorted
 * @start: leftmost element in the unsorted list
 * @size: size of the array
 * Return: index of the minimum element
 */
int find_minimum_index(const int *array, int start, size_t size)
{
	size_t j, min_idx = start;

	for (j = start + 1; j < size; j++)
		if (array[min_idx] > array[j])
			min_idx = j;

	return (min_idx);
}
