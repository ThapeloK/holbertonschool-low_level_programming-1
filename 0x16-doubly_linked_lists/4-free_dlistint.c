#include "lists.h"

/**
 * free_dlistint - frees doubly linked list
 * @head: doubly linked list
 * Return: Nothing
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp = head;

	while (head)
	{
		head = head->next;
		free(temp);
		temp = head;
	}
}
