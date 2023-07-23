#include "sort.h"

/**
 * list_len - Count a list of integers
 *
 * @list: The list to be counted
 * Return: The list lenght
 */
int list_len(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		++i;
		list = list->next;
	}
	return (i)
}
