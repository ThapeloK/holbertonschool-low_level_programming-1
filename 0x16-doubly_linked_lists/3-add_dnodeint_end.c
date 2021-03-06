#include "lists.h"

/**
 * add_dnodeint_end - adds a node at the end of a doubly linked list
 * @head: doubly linked list
 * @n: data for a node
 * Return: doubly linked list
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node = NULL;
	dlistint_t *current = *head;

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;

	if (!*head)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	while (current->next)
		current = current->next;
	current->next = new_node;
	new_node->prev = current;
	return (new_node);
}
