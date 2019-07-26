#include "binary_trees.h"

/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: pointer to root node of tree to check
 * Return: 1 if full, otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left && tree->right)
	{
		return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));
	}
	return (0);
}

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: binary tree
 * Return: height of the @tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
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
 * heapify - heapifies node
 * @node: inserted node
 * Return: returns the current node
 */
heap_t *heapify(heap_t *node)
{
	int temp;

	if (!node || !node->parent)
		return (node);
	while (node->parent)
	{
		if (node->n < node->parent->n)
			return (node);
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - function that inserts a value in Max Binary Heap
 * @root: binary tree
 * @value: value of the new node
 * Return: a pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *temp = NULL;
	int r_full, l_full, r_height, l_height;

	if (!root)
		return (NULL);
	if (!*root)
		return (*root = binary_tree_node(NULL, value));
	temp = *root;

	while (temp)
	{
		if (!temp->left)
		{
			temp->left = binary_tree_node(temp, value);
			if (!temp->left)
				return (NULL);
			return (heapify(temp->left));
		}
		else if (!temp->right)
		{
			temp->right = binary_tree_node(temp, value);
			if (!temp->right)
				return (NULL);
			return (heapify(temp->right));
		}
		r_full = binary_tree_is_full(temp->right);
		l_full = binary_tree_is_full(temp->left);
		r_height = binary_tree_height(temp->right);
		l_height = binary_tree_height(temp->left);
		if ((r_full && l_full && r_height == l_height)
		    || (r_full && !l_full && r_height != l_height))
			temp = temp->left;
		else
			temp = temp->right;
	}
	return (NULL);
}
