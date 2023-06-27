#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending
 * order using the Counting sort algorithm
 * @array: Pointer to array
 * @size: Size of the array
 **/
void counting_sort(int *array, size_t size)
{
	int max_val, j, *count_array, *output_array;
	size_t i;

	if (!array || size < 2)
		return;

	max_val = array[0];
	for (i = 0; i < size; i++)
		if (array[i] > max_val)
			max_val = array[i];

	count_array = calloc((max_val + 1), sizeof(int));
	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	for (j = 1; j <= max_val; j++)
		count_array[j] += count_array[j - 1];

	print_array(count_array, max_val + 1);

	output_array = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		output_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output_array[i];

	free(output_array);
	free(count_array);
}
