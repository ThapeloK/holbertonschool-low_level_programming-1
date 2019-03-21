#include "lists.h"

/**
 * free_list - frees given linked list
 * @head: first element of a linked list
 * Return: Nothing.
 */
void free_list(list_t *head)
{
	list_t *next_addr = head;
	list_t *prev_addr = head;

	while (next_addr->next != NULL)
	{
		free(next_addr->str);
		next_addr = next_addr->next;
		free(prev_addr);
		prev_addr = next_addr;
	}
	free(next_addr->str);
	free(prev_addr);
}
