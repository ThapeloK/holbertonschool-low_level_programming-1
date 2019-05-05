#include "lists.h"

/**
 * delete_dnodeint_at_index - Delete node at index
 * @head: Doubly linked list
 * @index: index
 * Return: 1 on success, 0 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;

	if (!*head)
		return (0);
	if (index == 0)
	{
		*head = (*head)->next;
		if (*head)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}
	while (temp && temp->next)
	{
		if (index == 0)
			break;
		index--;
		temp = temp->next;
	}
	if (index)
		return (0);
	temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	free(temp);
	return (1);
}
