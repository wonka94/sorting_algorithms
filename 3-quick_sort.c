#include "sort.h"

/**
 * lomuto_partition - partitions an array using the Lomuto
 * partition scheme
 * @array: pointer to the first element of the array to partition
 * @first: index of the first element in the array to partition
 * @last: index of the last element in the array to partition
 * @size: size of the array
 *
 * Return: final position of the pivot element
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t i = first - 1, j;
	int tmp;

	for (j = first; j < last; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != last)
	{
		tmp = array[i + 1];
		array[i + 1] = array[last];
		array[last] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * sort - Sort algorithm
 * @array: array
 * @first: first array element
 * @last: last array element
 * @size: array size
 */
void sort(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;


	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		sort(array, first, position - 1, size);
		sort(array, position + 1, last, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * QuickSort algorithm
 * @array: pointer to the first element of the array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	sort(array, 0, size - 1, size);
}
