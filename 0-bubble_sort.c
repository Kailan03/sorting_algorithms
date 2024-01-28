#include <stdio.h>
#include "sort.h"
/**
 * swap - swap elements of an array
 * @xp: first element
 * @yp: second element
 *
 * Return: 0
 */
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * bubble_sort - sorts array of integers
 * @arr: the array
 * @n: integer
 *
 * Return: sorted array
 */
void bubble_sort(int arr[], size_t n)
{
	size_t i, j, k;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				/* Printing array after each swap*/
				for (k = 0; k < n; k++)
				{
					printf("%d ", arr[k]);
				}
				printf("\n");
			}
		}
	}
}
