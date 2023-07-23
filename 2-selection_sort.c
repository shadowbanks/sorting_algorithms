#include "sort.h"

/**
 * selection_sort - Sort an array of integer using
 * selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, temp = 0, temp_min = 0;

	if (!array || size <= 2)
		return;

	for (; i < size - 1; i++)
	{
		temp_min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[temp_min])
				temp_min = j;
		}
		if (temp_min != i)
		{
			temp = array[i];
			array[i] = array[temp_min];
			array[temp_min] = temp;
			print_array(array, size);
		}
	}
}
