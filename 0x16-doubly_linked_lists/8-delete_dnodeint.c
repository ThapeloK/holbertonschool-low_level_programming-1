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
	uint i = 0;

	if (!head || !*head)
		return (0);
	if (index == 0)
	{
		*head = (*head)->next;
		if (*head)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	if (index >= i)
		return (0);
	temp = *head;
	while (temp && temp->next)
	{
		if (index == 0)
			break;
		index--;
		temp = temp->next;
	}
	if (i - 1 == index)
	{
		temp->prev->next = NULL;
		free(temp);
		return (1);
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp);
	return (1);
}
