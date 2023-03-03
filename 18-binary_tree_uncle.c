#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 *
 * @node: a pointer to the root node to find the uncle
 *
 * Return: a pointer to the uncle node
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle, *temp;

	/* check if node or parent node is NULL */
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
	{
		return (NULL);
	}

	temp = node->parent; /* temp points to parent */

	/* determine which parent of the parent temp was passed */
	if (temp->parent->left == temp)
	{
		uncle = temp->parent->right; /* get uncle */
	}

	else
	{
		uncle = temp->parent->left; /* get uncle */
	}

	return (uncle); /* return uncle */
}
