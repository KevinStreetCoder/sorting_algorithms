#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                        using the Insertion sort algorithm
 *
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	if (!list || !*list || !(*list)->next)
	return;

	listint_t *current, *next_node, *temp;

	current = (*list)->next;

	while (current != NULL)
	{
	next_node = current->next;
	while (current->prev != NULL && current->n < current->prev->n)
	{
		temp = current->prev;
		temp->next = current->next;
		if (current->next != NULL)
		current->next->prev = temp;
		current->prev = temp->prev;
		current->next = temp;
		if (temp->prev != NULL)
		temp->prev->next = current;
		temp->prev = current;
		if (temp == *list)
		*list = current;
		print_list(*list);
	}
	current = next_node;
	}
}
