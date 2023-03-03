#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 *
 * @node: a pointer to the root node to find the sibling
 *
 * Return: a pointer to the sibling node
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling;

	/* check if node or parent node is NULL */
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}

	/* determine which child of the parent node was passed */
    if (node->parent->left == node)
	{
        sibling = node->parent->right; /* get sibling */
	}

    else
	{
        sibling = node->parent->left; /* get sibling */
	}

    return (sibling); /* return sibling */
}
