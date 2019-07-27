#include "binary_trees.h"
#define swap(x, y) { *x = *x + *y; *y = *x - *y; *x = *x - *y; }

/**
 * height - function that measures the height of a binary tree
 * @tree: binary tree
 * Return: height of the @tree
 */
size_t height(const binary_tree_t *tree)
{
	size_t l_height;
	size_t r_height;

	if (tree == NULL)
		return (0);
	if (tree->left)
	{
		l_height = 1 + binary_tree_height(tree->left);
	}
	else
	{
		l_height = 0;
	}

	if (tree->right)
		r_height = 1 + binary_tree_height(tree->right);
	else
	{
		r_height = 0;
	}

	if (l_height > r_height)
		return (l_height);
	return (r_height);
}

/**
 * depth - returns depth of leftmost leaf
 * @tree: root tree or subtree
 * Return: depth
 */
int depth(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

/**
 * is_perfect - recursive function to check if bt is perfect
 * @tree: root
 * @depth: depth
 * @level: checks level
 * Return: 1 if true, 0 if false
 */
int is_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect(tree->left, depth, level + 1) &&
		is_perfect(tree->right, depth, level + 1));
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
			if (curr == *root)
			{
				temp = curr->n, free(curr), *root = NULL;
				return (temp);
			}
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
		r_full = is_perfect(curr->right, depth(curr->right), 0);
		l_full = is_perfect(curr->left, depth(curr->left), 0);
		r_height = height(curr->right);
		l_height = height(curr->left);
		if ((r_full && l_full && r_height < l_height)
		    || (r_full && !l_full && r_height != l_height)
		    || (!curr->right))
			curr = curr->left;
		else
			curr = curr->right;
	}
	return (0);
}
