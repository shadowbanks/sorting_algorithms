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
	node temp = NULL, prev_n = NULL, current = NULL;

	if (!list || !(*list) || list_len(*list) < 2)
		return;

	current = (*list)->next;

	for (; current != NULL; current = current->next)
	{
		for (temp = current; temp != NULL; temp = temp->prev)
		{
			prev_n = temp->prev;
			if (prev_n != NULL && temp->n < prev_n->n)
			{
				prev_n->next = temp->next;
				if (prev_n->next != NULL)
					temp->next->prev = prev_n;
				temp->next = prev_n;
				temp->prev = prev_n->prev;
				if (temp->prev != NULL)
					prev_n->prev->next = temp;
				prev_n->prev = temp;
				if (temp->prev == NULL)
					*list = temp;
				print_list(*list);
			}
		}
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
