#include "lists.h"

/**
 * find_listint_loop - finds the first member of a linked list
 * @head: pointer to the head
 * Return: number of nodes
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *temp = head;

	if (!head)
		return (NULL);
	while (temp && temp > temp->next)
		temp = temp->next;
	if (temp)
		return (temp->next);
	return (NULL);
}
