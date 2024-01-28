#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *
 * @list: Pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = current->next)
	{
		temp = current;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			/* Swap nodes if needed */
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;

			/* Update head if temp is the new head */
			if (temp->prev == NULL)
				*list = temp;
			/* Print list after each swap */
			print_list(*list);
		}
	}
}
