#include "binary_trees.h"

/**
 * binary_tree_is_bst -  checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	/* if tree is NULL */
	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left->n > tree->n || tree->right->n < tree->n)
	{
		return (0);
	}

	return (binary_tree_is_bst(tree->left) && binary_tree_is_bst(tree->right));
}
