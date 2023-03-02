#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a node is a root
 *
 * @node: a pointer to the node to check
 *
 * Return: 1 if node is a root, otherwise 0
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	/* node is NULL */
	if (node == NULL)
	{
		return (0);
	}

	/* check parent node */
	if (node->parent == NULL)
	{
		return (1); /* node is a root */
	}

	return (0); /* node is not a root */
}
