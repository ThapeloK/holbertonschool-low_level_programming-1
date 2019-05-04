#include "lists.h"

/**
 * get_dnodeint_at_index - Gets node at index
 * @head: Doubly linked lists
 * @index: index of the node
 * Return: The node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	while (head)
	{
		index--;
		head = head->next;
		if (index == 0)
			return (head);
	}
	return (NULL);
}
