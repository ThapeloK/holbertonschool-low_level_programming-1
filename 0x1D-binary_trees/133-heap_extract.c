#include "binary_trees.h"

/**
 * swap - Swaps two numbers
 * @n1: First number
 * @n2: Second number
 * Return: Nothing
 */
void swap(int *n1, int *n2)
{
	int temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

/**
 * full_heapify - heapifies full tree
 * @node: node of binary tree
 * Return: Nothing.
 */
void full_heapify(heap_t *node)
{
	if (!node || (!node->left && !node->right))
		return;
	while (node)
	{
		if (node->left && node->right && node->n < node->right->n &&
		    node->n < node->left->n && node->left->n < node->right->n)
		{
			swap(&node->n, &node->right->n);
			node = node->right;
		}
		else if (node->left && node->right && node->n < node->right->n
			 && node->n < node->left->n
			 && node->left->n > node->right->n)
		{
			swap(&node->n, &node->left->n);
			node = node->left;
		}
		else if (node->left && node->left->n > node->n)
		{
			swap(&node->n, &node->left->n);
			node = node->left;
		}
		else if (node->right && node->right->n > node->n)
		{
			swap(&node->n, &node->right->n);
			node = node->right;
		}
		else
			return;
	}
}

/**
 * heap_extract - function that extracts the root node of a Max Binary Heap
 * @root: root of binary tree
 * Return: value of removed node on success, 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *curr = NULL;
	int r_full, l_full, r_height, l_height, temp;

	if (!root || !*root)
		return (0);
	curr = *root;
	while (curr)
	{
		if (!curr->left && !curr->right)
		{
			temp = (*root)->n;
			(*root)->n = curr->n;
			curr->n = temp;
			if (curr->parent && curr->parent->left == curr)
				curr->parent->left = NULL;
			else if (curr->parent)
				curr->parent->right = NULL;
			free(curr);
			full_heapify(*root);
			return (temp);
		}
		r_full = binary_tree_is_perfect(curr->right);
		l_full = binary_tree_is_perfect(curr->left);
		r_height = binary_tree_height(curr->right);
		l_height = binary_tree_height(curr->left);
		if ((r_full && l_full && r_height < l_height)
		    || (r_full && !l_full && r_height != l_height)
		    || (!curr->right))
			curr = curr->left;
		else
			curr = curr->right;
	}
	return (0);
}
