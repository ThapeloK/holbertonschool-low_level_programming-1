#include "sort.h"

/**
 * swap_node - Swaps two numbers
 * @a: First number
 * @b: Second number
 * Return: Nothing
 */
void swap_node(listint_t *a, listint_t *b)
{
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
 * cocktail_sort_list - Cocktail shaker sort
 * @list: Doubly linked list
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	char flag = 0;
	listint_t *current;

	if (!list || !*list)
		return;
	current = *list;
	for (;;)
	{
		flag = 0;
		for (; current->next;)
		{
			if (current->next->n < current->n)
			{
				swap_node(current, current->next);
				print_list(*list);
				flag = 1;
			}
			else
				current = current->next;
		}
		for (; current->prev;)
		{
			if (current->prev->n > current->n)
			{
				swap_node(current->prev, current);
				if (!current->prev)
					*list = current;
				print_list(*list);
				flag = 1;
			}
			else
				current = current->prev;
		}
		if (flag == 0)
			break;
	}
}
