#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: array to be sorted
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;

	if (!array || size < MIN_SIZE)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && less(array[j], array[j - gap]); j -= gap)
				swap(&array[j], &array[j - gap]);
		}
		print_array(array, size);
		gap /= 3;
	}
}

/**
 * less - checks if first element is less than second element
 * @first: first element
 * @second: second element
 * Return: 1 if first is less than second, 0 otherwise
 */
int less(int first, int second)
{
	return (compare_to(first, second) < 0);
}

/**
 * compare_to - compares two integers
 * @first: first integer
 * @second: second integer
 * Return: 1 if first is greater than second, -1 if first is less than second,
 */
int compare_to(int first, int second)
{
	return (first > second ? 1 : first < second ? -1 : 0);
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
