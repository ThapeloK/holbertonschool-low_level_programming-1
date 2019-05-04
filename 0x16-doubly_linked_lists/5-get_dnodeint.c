#include "lists.h"

/**
 * get_dnodeint_at_index - Gets node at index
 * @head: Doubly linked lists
 * @index: index of the node
 * Return: The node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	uint i = 0;

	while (head)
	{
		if (i == index)
			return (head);
		head = head->next;
		i++;
	}
	return (NULL);
}
