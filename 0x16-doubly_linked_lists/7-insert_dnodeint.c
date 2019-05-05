#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a node at a given index
 * @h: linked list
 * @idx: index
 * @n: data for a node
 * Return: Address of the new node, NULL if fails
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current = *h;
	dlistint_t *new_node = NULL;
	uint i = 0;

	if (!h)
		return (NULL);
	while (current)
	{
		current = current->next;
		i++;
	}
	if (idx == 0)
		return (add_dnodeint(h, n));
	if (i < idx)
		return (NULL);
	if (idx == i)
		return (add_dnodeint_end(h, n));
	current = *h;
	while (current && current->next)
	{
		if (idx == 0)
			break;
		idx--;
		current = current->next;
	}
	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);
	new_node->n = n;

	current->prev->next = new_node;
	new_node->prev = current->prev;
	current->prev = new_node;
	new_node->next = current;
	return (new_node);
}
