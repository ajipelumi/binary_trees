#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 *
 * @parent: pointer to the parent node of the node to create
 * @value: the value to put in the new node
 *
 * Return: a pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* create new node in memory */
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL) /* malloc fails */
	{
		return (NULL);
	}

	new_node->n = value; /* store value in new node */
	new_node->parent = parent; /* store parent node */
	new_node->left = new_node->right = NULL;

	/* parent is NULL means the root */
	if (parent == NULL)
	{
		return (new_node);
	}

	/* parent now points to new node */
	parent = new_node;

	return (new_node);
}
