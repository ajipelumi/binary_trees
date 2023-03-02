#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the size
 *
 * Return: tree size, 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 1;

	/* Base case */
	if (tree == NULL)
	{
		return (0);
	}

	/* increment size for every recursive call to left subtree */
	size += binary_tree_size(tree->left);
	/* increment size for every recursive call to right subtree */
	size += binary_tree_size(tree->right);

	return (size); /* return size of tree */
}
