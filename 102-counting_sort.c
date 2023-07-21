#include "sort.h"

/**
 * counting_sort - algorithm
 * @array: array to be sorted
  *@size: array size
 */
void counting_sort(int *array, size_t size)
{
	int idx, max;
	int *count, *final_array;

	if (!array || size < 2)
		return;

	max = get_max(array, size);
	count = generate_count_array(max, array, size);
	final_array = malloc(sizeof(int) * size);

	for (idx = size - 1; idx >= 0; idx--)
		final_array[--count[array[idx]]] = array[idx];

	for (idx = 0; idx < (int)size; idx++)
		array[idx] = final_array[idx];

	print_array(count, max + 1);

	free(count);
	free(final_array);
}

/**
 * get_max - gets the max number in the array
 * @array: array to be sorted
 * @size: array size
 * Return: max number in array
*/
int get_max(int *array, size_t size)
{
	int max = array[0], idx;

	for (idx = 1; idx < (int)size; idx++)
		if (max < array[idx])
			max = array[idx];

	return (max);
}

/**
 * generate_count_array - generates the count array
 * @max: maximum number in the array
 * @array: array to be sorted
 * @size: array size
 * Return: count array
*/
int *generate_count_array(int max, int *array, size_t size)
{
	int idx;
	int *count = malloc(sizeof(int) * (max + 1));

	for (idx = 0; idx <= max; idx++)
		count[idx] = 0;

	for (idx = 0; idx < (int)size; idx++)
	{
		count[array[idx]]++;
	}

	for (idx = 1; idx <= max; idx++)
		count[idx] += count[idx - 1];

	return (count);
}
