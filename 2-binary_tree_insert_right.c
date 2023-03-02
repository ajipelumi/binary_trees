#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 *
 * @parent: pointer to the node to insert the right-child in
 * @value: the value to put in the new node
 *
 * Return: a pointer to the created node, NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *temp;

	/* if parent is NULL */
	if (parent == NULL)
	{
		return (NULL);
	}

	/* create new node in memory */
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL) /* malloc fails */
	{
		return (NULL);
	}

	new_node->n = value; /* store value in new node */
	new_node->parent = parent; /* store parent node */
	new_node->left = new_node->right = NULL;

	/* if right of parent points to a node already */
	if (parent->right != NULL)
	{
		temp = parent->right; /* temp points to node to be replaced */
		temp->parent = new_node; /* parent of temp points to new node */
		new_node->right = temp; /* right of new node points to temp */
	}

	/* right of parent now points to new node */
	parent->right = new_node;

	return (new_node);
}
