#include "search_algos.h"

/**
 * linear_skip - Linked List with an express lane
 * @list: Linked list
 * @value: Value to be searched
 * Return: Index where @value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current;
	skiplist_t *prev;

	if (!list)
		return (NULL);

	current = list->express;
	prev = list;
	while (current)
	{
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
		if (current->n > value)
		{
			break;
		}
		prev = current;
		if (!current->express)
		{
			while (current->next)
				current = current->next;
			break;
		}
		current = current->express;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
	       prev->index, current->index);
	while (prev && prev->index <= current->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
		{
			return (prev);
		}
		prev = prev->next;
	}
	return (NULL);
}
