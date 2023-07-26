#include "sort.h"

/**
 * heap_sort - algorithm
 * @array: array to be sorted
 * @size: array size
 */
void heap_sort(int *array, size_t size)
{
	int node;
	size_t end = size;

	if (!array || size < MIN_SIZE)
		return;

	build_heap(array, end, size);

	for (node = (int) size - 1; node > 0; node--)
	{
		swap(&array[START_INDEX], &array[node]);
		print_array(array, size);
		heapify(array, START_INDEX, node, size);
	}
}

/**
 * build_heap - builds the heap
 * @array: array to be sorted
 * @end: end index
 * @size: array size
 */
void build_heap(int *array, size_t end, size_t size)
{
	int node;

	for (node = (int) size / 2 - 1; node >= 0; node--)
		heapify(array, node, end, size);
}

/**
 * heapify - make parent_idx node the largest
 * @array: array to be sorted
 * @parent_idx: parent_idx node
 * @end: end index
 * @size: array size
 */
void heapify(int *array, int parent_idx, size_t end, size_t size)
{
	int left_child_idx = 2 * parent_idx + 1;
	int right_child_idx = 2 * parent_idx + 2;
	int max_idx = parent_idx;


	if (left_child_idx < (int) end && array[left_child_idx] > array[max_idx])
		max_idx = left_child_idx;

	if (right_child_idx < (int) end && array[right_child_idx] > array[max_idx])
		max_idx = right_child_idx;

	if (max_idx != parent_idx)
	{
		swap(&array[parent_idx], &array[max_idx]);
		print_array(array, size);
		heapify(array, max_idx, end, size);
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
