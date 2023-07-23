#include "sort.h"

/**
 * insertion_sort_list - This sorts a double linked list of integers
 * in ascending order using insertion sort
 * @list: pointer to doubly linked list
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *tmp;

	if (*list == NULL || (*list)->next == NULL || list_len(*list) < 2)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		tmp = curr->prev;
		while (tmp != NULL && tmp->n > curr->n)
		{
			if (tmp->prev)
				tmp->prev->next = curr;
			if (curr->next)
				curr->next->prev = tmp;

			tmp->next = curr->next;
			curr->prev = tmp->prev;

			curr->next = tmp;
			tmp->prev = curr;

			if (curr->prev == NULL)
				*list = curr;

			tmp = curr->prev;
			print_list(*list);
		}
		curr = curr->next;
	}
}

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
	return (i);
}
