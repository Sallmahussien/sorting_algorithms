#include "sort.h"

/**
 * merge_sort - algorithm
 * @array: array to be sorted
 * @size: array size
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (!array || size < MIN_SIZE)
		return;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;

	top_down_split(array, buffer, 0, size - 1);

	free(buffer);
}

/**
 * top_down_split - splits the array
 * @array: array to be sorted
 * @buffer: buffer
 * @low: low index
 * @high: high index
 */
void top_down_split(int *array, int *buffer, int low, int high)
{
	int mid;

	if (low < high)
	{
		if ((high - low + 1) % 2 == 0)
			mid = low + ((high - low) / 2);
		else
			mid = low + ((high - low) / 2) - 1;

		top_down_split(array, buffer, low, mid);
		top_down_split(array, buffer, mid + 1, high);

		merge_array(array, buffer, low, mid, high);
	}
}

/**
 * merge_array - merges two sub array
 * @array: array to be sorted
 * @buffer: buffer
 * @low: low index
 * @mid: mid index
 * @high: high index
*/
void merge_array(int *array, int *buffer, int low, int mid, int high)
{
	int i = low, j = mid + 1, k = low;
	int idx;

	printf("Merging...\n");
	printf("[left]: ");
	print_sub_array(array, low, mid);
	printf("[right]: ");
	print_sub_array(array, mid + 1, high);

	for (idx = 0; idx <= high; idx++)
		buffer[idx] = array[idx];

	while (i <= mid && j <= high)
	{
		if (buffer[i] < buffer[j])
			array[k++] = buffer[i++];
		else
			array[k++] = buffer[j++];
	}

	while (i <= mid)
		array[k++] = buffer[i++];

	while (j <= high)
		array[k++] = buffer[j++];

	printf("[Done]: ");
	print_sub_array(array, low, high);
}

/**
 * print_sub_array - prints sub array
 * @array: array to be sorted
 * @start: start index
 * @end: end index
*/
void print_sub_array(int *array, int start, int end)
{
	int idx;

	for (idx = start; idx <= end; idx++)
	{
		printf("%d", array[idx]);
		if (idx != end)
			printf(", ");
	}
	printf("\n");
}
