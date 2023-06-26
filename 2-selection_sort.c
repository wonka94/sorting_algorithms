#include "sort.h"
/**
 * selection_sort - Sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @size: size of the array
 * @array: array to sort
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, min_index, swap = 0;

	if (array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		min_index = i;
		swap = 0;
		for (j = i + 1; j < size; j++)
		{
			if (array[min_index] > array[j])
			{
				min_index = j;
				swap += 1;
			}
		}
		temp = array[i];
		array[i] = array[min_index];
		array[min_index] = temp;
		if (swap != 0)
			print_array(array, size);
	}
}
