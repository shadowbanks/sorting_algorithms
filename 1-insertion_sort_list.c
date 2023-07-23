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

	if (!list || !(*list) || list_len(*list) <= 2)
		return;

	current = (*list)->next;

	for (; current != NULL; current = current->next)
	{
		temp = current;
		for (; temp != NULL; temp = temp->prev)
		{
			prev_n = temp->prev;
			if (prev_n != NULL && temp->n < prev_n->n)
			{
				temp->prev = temp->prev->prev;
				prev_n->prev = prev_n->next;
				prev_n->next = temp->next;
				temp->next->prev = prev_n;
				temp->next = prev_n;
				print_list(list);
			}
			else
				break;
		}
	}
}
