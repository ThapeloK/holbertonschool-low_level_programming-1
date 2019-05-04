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
	dlistint_t *temp = *h;
	dlistint_t *new_node = NULL;

	if (idx == 0)
		return (add_dnodeint(h, n));
	while (temp && temp->next)
	{
		if (idx == 0)
			break;
		idx--;
		temp = temp->next;
	}
	if (idx || !*h)
		return (NULL);
	if (!temp->next)
		return (add_dnodeint_end(h, n));

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);
	new_node->n = n;

	temp->prev->next = new_node;
	new_node->prev = temp->prev;
	new_node->next = temp;
	temp->prev = new_node;
	return (new_node);
}
