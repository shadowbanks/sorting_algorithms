#include "sort.h"

/**
 * bubble_sort - Sort an array of integers
 * in ascending order using Bubble sert algorithm
 * @array: integer array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{
	int swap = 1, i = 1, len = 0, temp = 0;

	if (array):
		len = sizeof(array) / sizeof(array[0]);

	while (swap)
	{
		swap = 0
		for (; i < n; i++)
		{
			if (array[i] < array[i - 1])
			{
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
				swap = 1;
				print_array(array);
			}
		}
		n--;
	}
}
