#include "sort.h"

/**
 * shell_sort - Sort an array of integer using shell sort
 * @array: the array to be sorted
 * @size: array size
 *
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1, i = 0, j = 0, temp = 0, len = 0;

	len = size;
	if (!array || len < 2)
		return;

	while (gap <= len / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		i = gap;
		while (i < len)
		{
			j = i - gap;

			while (j >= 0)
			{
				if (array[j + gap] > array[j])
					break;
				/* Swap values when if fails*/
				temp = array[j];
				array[j] = array[j + gap];
				array[j + gap] = temp;

				j = j - gap;
			}
			i++;
		}
		print_array(array, len);
		gap = (gap - 1) / 3;
	}
}
