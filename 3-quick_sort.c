#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_recursive(array, 0, size - 1, size);
}

/**
 * quicksort_recursive - Recursively sorts a partition of an array using
 * the Quick sort algorithm with Lomuto partition scheme.
 *
 * @array: The array to be sorted.
 * @low: The low index of the partition.
 * @high: The high index of the partition.
 * @size: The size of the array.
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	{
		partition_index = lomuto_partition(array, low, high, size);
		quicksort_recursive(array, low, partition_index - 1, size);
		quicksort_recursive(array, partition_index + 1, high, size);
	}
}

/**
 * lomuto_partition - Partitions an array using the Lomuto partition scheme.
 *
 * @array: The array to be partitioned.
 * @low: The low index of the partition
 * @high: The high index of the partition.
 * @size: The size of the array.
 *
 * Return: The partition index.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * swap - Swaps two integers.
 *
 * @xp: Pointer to the first integer.
 * @yp: Pointer to the second integer.
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
