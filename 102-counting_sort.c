#include "sort.h"

/**
 * counting_sort - Sort an array of integers using count sort
 * @array: the array to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int *result = NULL, *count = NULL, i = 0, max = 0, len = 0;

	if (!array || size < 2)
		return;

	len = size;
	/*Find the largest number in the array*/
	max = array[0];

	for (i = 1; i < len; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;

	/* Initialize count array with all zeros */
	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (i = 0; i < len; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	result = malloc(sizeof(int) * len);
	if (result == NULL)
	{
		free(count);
		return;
	}

	for (i = len - 1; i >= 0; i--)
	{
		result[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < len; i++)
		array[i] = result[i];

	free(result);
	free(count);
}
