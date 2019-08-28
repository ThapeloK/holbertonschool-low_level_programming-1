#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Jump List
 * @list: Linked list
 * @size: Size of the @list
 * @value: Value to be searched
 * Return: Index where @value is located
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step;
	listint_t *current = list;
	listint_t *prev = NULL;
	listint_t *next = NULL;

	if (!list || size == 0)
		return (NULL);

	step = sqrt(size);
	while (current)
	{
		prev = current;
		while (current->next && current->index < step)
		{
			current = current->next;
		}
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
		if (current->n > value || current->index == size - 1)
		{
			next = current;
			printf("Value found between indexes [%lu] and [%lu]\n",
			       prev->index, next->index);
			break;
		}
		step += sqrt(size);
	}

	while (prev && prev->index <= next->index)
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
