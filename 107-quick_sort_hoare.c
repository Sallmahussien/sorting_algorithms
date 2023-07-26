#include "sort.h"

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < MIN_SIZE)
		return;

	quick_sort_hoare_array(array, START_INDEX, size - 1, size);
}

/**
 * quick_sort_hoare_array - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @low: low index
 * @high: high index
 * @size: size of the array
 */
void quick_sort_hoare_array(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_idx = partition_hoare(array, low, high, size);

		quick_sort_hoare_array(array, low, pivot_idx, size);
		quick_sort_hoare_array(array, pivot_idx + 1, high, size);
	}
}

/**
 * partition_hoare - Hoare partition_hoare scheme
 * @array: array to be sorted
 * @low: low index
 * @high: high index
 * @size: size of the array
 * Return: index of the pivot
 */
int partition_hoare(int *array, int low, int high, size_t size)
{
	int i = low - 1;
	int j = high + 1;
	int pivot = array[high];

	while (true)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i > j)
			return (j);

		if (i != j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
}

/**
 * swap - swaps two elements
 * @first_element: first element
 * @second_element: second element
 */
void swap(int *first_element, int *second_element)
{
	int temp = *first_element;
	*first_element = *second_element;
	*second_element = temp;
}
