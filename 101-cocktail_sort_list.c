#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm
 *
 * @list: Double pointer to the head of the list
 *
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;

		tmp = *list;
		while (tmp->next != NULL)
		{
			if (tmp->n > tmp->next->n)
			{
				swap_nodes(list, tmp, tmp->next);
				print_list(*list);
				swapped = 1;
			}
			else
				tmp = tmp->next;
		}

		if (!swapped)
			break;

		swapped = 0;
		tmp = tmp->prev;
		while (tmp->prev != NULL)
		{
			if (tmp->n < tmp->prev->n)
			{
				swap_nodes(list, tmp->prev, tmp);
				print_list(*list);
				swapped = 1;
			}
			else
				tmp = tmp->prev;
		}
	} while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Double pointer to the head of the list
 * @node1: First node to swap
 * @node2: Second node to swap
 *
 * Return: Nothing
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev1, *next2;

	prev1 = node1->prev;
	next2 = node2->next;

	if (prev1 != NULL)
		prev1->next = node2;
	else
		*list = node2;

	if (next2 != NULL)
		next2->prev = node1;

	node1->prev = node2;
	node1->next = next2;

	node2->prev = prev1;
	node2->next = node1;
}
