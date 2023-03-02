#include "binary_trees.h"

/**
 * binary_tree_leaves - count the leaves of a binary tree
 *
 * @tree: a pointer to the root node of the tree to count the leaves
 *
 * Return: tree leaves, 0 if tree is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	/* Base case */
	if (tree == NULL)
	{
		return (0);
	}

	/* left and right point to NULL which indicate a leaf */
	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}

	/* increment leaves for every recursive call to left subtree */
	leaves += binary_tree_leaves(tree->left);
	/* increment leaves for every recursive call to right subtree */
	leaves += binary_tree_leaves(tree->right);

	return (leaves); /* return leaves of tree */
}
