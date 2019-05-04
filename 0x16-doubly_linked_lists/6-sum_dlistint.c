#include "lists.h"

/**
 * sum_dlistint - Sums all data of a linked list
 * @head: doubly linked list
 * Return: Sum of nodes
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
