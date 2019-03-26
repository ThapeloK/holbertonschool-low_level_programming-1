#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a node at a given position
 * @head: reference pointer
 * @idx: nth node after which a new element is inserted
 * @n: data
 * Return: The address of a new node or NULL if it fails
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node;
	listint_t *current = *head;
	listint_t *prev = *head;
	unsigned int i = 0;

	if (idx == 0)
	{
		new_node = malloc(sizeof(listint_t));
		if (!new_node)
			return (NULL);
		new_node->n = n;
		new_node->next = *head;
		*head = new_node;
		return (*head);
	}
	while (current)
	{
		if (i == idx)
		{
			new_node = malloc(sizeof(listint_t));
			if (!new_node)
				return (NULL);
			new_node->n = n;
			new_node->next = current;
			prev->next = new_node;
			return (new_node);
		}
		prev = current;
		current = current->next;
		i++;
	}
	return (NULL);
}
