#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the depth
 *
 * Return: tree depth, 0 if tree is NULL
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 1;

	/* Base case */
	if (tree == NULL || tree->parent == NULL)
	{
		return (0);
	}

	/* increment depth for every recursive call to parent */
	depth += binary_tree_depth(tree->parent);

	return (depth); /* return depth of tree */
}
