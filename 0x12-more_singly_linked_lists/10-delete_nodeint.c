#include "lists.h"

/**
 * delete_nodeint_at_index - deletes nth element
 * @head: a pointer to the head
 * @index: index of a node to be removed
 * Return: Return 1 if succes or -1 when it fails
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *nt = *head;
	listint_t *prev;

	if (index == 0)
	{
		if (!nt)
			return (-1);
		*head = (*head)->next;
		free(nt);
		return (1);
	}
	for (i = 0; i <= index; i++)
	{
		if (!nt)
			return (-1);
		prev = nt;
		nt = nt->next;
	}
	if (!nt)
		return (-1);
	prev->next = nt->next;
	free(nt);
	return (1);
}
