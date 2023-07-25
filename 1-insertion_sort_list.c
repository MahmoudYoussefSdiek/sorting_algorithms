#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the Insertion sort algorithm
 *
 * @list: Pointer to a pointer to the head of the list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		while (current->prev != NULL && current->n < current->prev->n)
		{
			previous = current->prev;

			previous->next = current->next;
			if (current->next != NULL)
				current->next->prev = previous;

			current->prev = previous->prev;
			current->next = previous;

			if (previous->prev != NULL)
				previous->prev->next = current;
			else
				*list = current;

			previous->prev = current;
			print_list(*list);

			current = previous;
		}
		current = next;
	}
}
