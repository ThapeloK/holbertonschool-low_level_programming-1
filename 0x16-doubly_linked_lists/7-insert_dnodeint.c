#include "lists.h"

/**
 * _len - returns the length of a doubly linked list
 * @h: doubly linked list
 * Return: Number of nodes
 */
size_t _len(const dlistint_t *h)
{
	size_t c = 0;

	while (h)
	{
		c++;
		h = h->next;
	}
	return (c);
}


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
	/* uint i = _len(current); */

	if (!h)
		return (NULL);
	if (idx == 0)
		return (add_dnodeint(h, n));
	while (current && current->next)
	{
		if (idx == 0)
			break;
		idx--;
		current = current->next;
	}
	if (idx || !*h)
		return (NULL);
	if (!current->next)
		return (add_dnodeint_end(h, n));

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);
	new_node->n = n;

	current->prev->next = new_node;
	new_node->prev = current->prev;
	new_node->next = current;
	current->prev = new_node;
	return (new_node);
}
