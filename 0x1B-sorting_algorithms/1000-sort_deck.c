#include "deck.h"

/**
 * swap_node - Swaps two nodes
 * @a: First node
 * @b: Second node
 * Return: Nothing
 */
void swap_node(deck_node_t *a, deck_node_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * get_index - Gets index of a card
 * @node: cards
 * Return: Index
 */

int get_index(deck_node_t *node)
{
	int index = 0;
	char *value = (char *)node->card->value;

	index = node->card->kind * 13;
	if (value[0] == 'K')
		index += 13;
	else if (value[0] == 'Q')
		index += 12;
	else if (value[0] == 'J')
		index += 11;
	else if (value[0] == '1' && value[1])
		index += 10;
	else if (value[0] == 'A')
		index += 1;
	else
		index += value[0] - '0';
	return (index);
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: unsorted deck of cards
 * Return: Nothing.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current  = NULL;
	deck_node_t *iter = NULL;

	if (!deck || !*deck || !(*deck)->next)
		return;

	current = (*deck)->next;
	while (current)
	{
		iter = current;
		current = current->next;
		while (iter && iter->prev)
		{
			if (get_index(iter->prev) > get_index(iter))
			{
				swap_node(iter->prev, iter);
				if (!iter->prev)
					*deck = iter;
			}
			else
				iter = iter->prev;
		}
	}
}
