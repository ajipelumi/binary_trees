#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 *
 * @parent: pointer to the node to insert the left-child in
 * @value: the value to put in the new node
 *
 * Return: a pointer to the created node, NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
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

	/* if left of parent points to a node already */
	if (parent->left != NULL)
	{
		temp = parent->left;
		temp->parent = new_node;
		new_node->left = temp;
	}

	/* left of parent now points to new node */
	parent->left = new_node;

	return (new_node);
}
