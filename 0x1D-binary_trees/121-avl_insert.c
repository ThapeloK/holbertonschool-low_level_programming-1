#include "binary_trees.h"

/**
 * bst_insert - function that inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *cur = NULL, *new = NULL;

	if (tree == NULL)
		return (NULL);
	new = binary_tree_node(NULL, value);
	if (new == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = new;
		return (*tree);
	}
	cur = *tree;
	while (cur != NULL)
	{
		if (value == cur->n)
		{
			free(new);
			return (NULL);
		}
		if (value < cur->n)
		{
			if (!cur->left)
			{
				new->parent = cur, cur->left = new;
				return (new);
			}
			cur = cur->left;
		}
		else if (value > cur->n)
		{
			if (!cur->right)
			{
				new->parent = cur, cur->right = new;
				return (new);
			}
			cur = cur->right;
		}
	}
	return (NULL);
}

/**
 * rebalance - rebalances BST tree, makes it AVL tree
 */

/* avl_t *rebalance(avl_t *node) */
/* { */
/* 	if (blc > 1 && value < (*tree)->n) /\*ll*\/ */
/* 	{ */
/* 		return (binary_tree_rotate_right((*tree))); */
/* 	} */
/* 	else if (blc > 1 && value > (*tree)->n) /\*lr*\/ */
/* 	{ */
/* 		(*tree)->left = binary_tree_rotate_left((*tree)->left); */
/* 		(*tree)->left->parent = (*tree); */
/* 		return (binary_tree_rotate_right((*tree))); */
/* 	} */
/* 	if (blc < -1 && value < (*tree)->n) /\*rr*\/ */
/* 	{ */
/* 		return (binary_tree_rotate_right((*tree))); */
/* 	} */
/* 	else if (blc < -1 && value > (*tree)->n) /\*rl*\/ */
/* 	{ */
/* 		(*tree)->right = binary_tree_rotate_right((*tree)->right); */
/* 		(*tree)->right->parent = (*tree); */
/* 		return (binary_tree_rotate_left((*tree))); */
/* 	} */
/* } */


/**
 * avl_insert - function that inserts a value in an AVL Tree
 * @tree: root node of the AVL tree for inserting the value
 * @value: value to insert
 * Return: AVL tree
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	int blc;
	avl_t *new = NULL, *temp = NULL;
	avl_t *temp2 = NULL;

	new = bst_insert(tree, value);
	temp = new;
	while (temp)
	{
		blc = binary_tree_balance(temp->parent);
		printf("\nBLC: %d\n\n", blc);
		if (blc > 1 && value < temp->parent->n)
		{
			printf("Rotating %d\n", temp->parent->n);
			temp2 = binary_tree_rotate_right(temp->parent);
			temp2->parent = temp->parent;
			break;
		}
		/* if (temp->parent) */
		/* { */
		/* 	blc = binary_tree_height(temp->parent->left) - */
		/* 		binary_tree_height(temp->parent->right); */
		/* 	if (abs(blc) > 1) */
		/* 	{ */
		/* 		/\* rebalance(); *\/ */
		/* 		printf("Not AVL tree left: %lu  right: %lu %d\n" */
		/* 		       , _height(temp->parent->left) */
		/* 		       , _height(temp->parent->right) */
		/* 		       , temp->parent->n); */
		/* 		break; */
		/* 	} */
		/* } */
		temp = temp->parent;
	}

	return (new);
}
