#include "sort.h"

/**
 * swap - Swaps two numbers
 * @n1: First number
 * @n2: Second number
 * Return: Nothing
 */
void swap_node(listint_t *a, listint_t *b)
{
	/* listint_t *prev; */

	/* prev = (*head)->prev; */
	/* if ((*head)->prev->prev) */
	/* 	(*head)->prev->prev->next = *head; */
	/* (*head)->prev = (*head)->prev->prev; */
	/* prev->prev = *head; */
	/* prev->next = (*head)->next; */
	/* (*head)->next = prev; */
	/* (*head)->next = prev; */
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - Insertion sort
 * @list: Linked list to be sorted
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current  = NULL;
	listint_t *iter = NULL;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while(current)
	{
		iter = current;
		current = current->next;
		while (iter && iter->prev)
		{
			if (iter->prev->n > iter->n)
			{
				swap_node(iter->prev, iter);
				if (!iter->prev)
					*list = iter;
				print_list(*list);
			}
			else
				iter = iter->prev;
		}
	}
}
