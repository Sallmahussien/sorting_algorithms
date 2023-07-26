#include "sort.h"

/**
 * bitonic_sort - algorithm
 * @array: array to be sorted
 * @size: array size
 */
void bitonic_sort(int *array, size_t size)
{
	size_t count = size;

	if (!array || size < MIN_SIZE)
		return;

	recursive_bitonic_sort(array, START_INDEX, count, size, true);
}

/**
 * recursive_bitonic_sort - recursive function
 * @array: array to be sorted
 * @low: low index
 * @count: count
 * @size: size
 * @ascending: ascending or descending
 */
void recursive_bitonic_sort(int *array, int low, size_t count,
							size_t size, bool ascending)
{
	size_t half_size;

	if (count > 1)
	{
		half_size = count / 2;

		printf("Merging [%d/%d] (%s):\n", (int) count, (int) size,
			   ascending ? "UP" : "DOWN");
		print_array(&array[low], count);

		recursive_bitonic_sort(array, low, half_size, size, true);
		recursive_bitonic_sort(array, low + (int) half_size, half_size, size, false);

		bitonic_merge(array, low, count, ascending);

		printf("Result [%d/%d] (%s):\n", (int) count, (int) size,
			   ascending ? "UP" : "DOWN");
		print_array(&array[low], count);
	}
}

/**
 * bitonic_merge - merge
 * @array: array to be sorted
 * @low: low index
 * @count: count
 * @ascending: ascending or descending
 */
void bitonic_merge(int *array, int low, size_t count, bool ascending)
{
	size_t half_size;
	int idx;

	if (count > 1)
	{
		half_size = count / 2;

		for (idx = low; idx < low + (int) half_size; idx++)
			if ((array[idx] > array[idx + half_size]) == ascending)
				swap(&array[idx], &array[idx + half_size]);

		bitonic_merge(array, low, half_size, ascending);
		bitonic_merge(array, low + (int) half_size, half_size, ascending);
	}
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
