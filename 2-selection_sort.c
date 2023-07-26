#include "sort.h"

/**
 * selection_sort - algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t curr_idx, min_idx;

	if (!array || size < MIN_SIZE)
		return;

	for (curr_idx = 0; curr_idx < size - 1; curr_idx++)
	{
		min_idx = find_minimum_index(array, (int) curr_idx, size);

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
size_t find_minimum_index(const int *array, int start, size_t size)
{
	size_t j, min_idx = start;

	for (j = start + 1; j < size; j++)
		if (array[min_idx] > array[j])
			min_idx = j;

	return (min_idx);
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
