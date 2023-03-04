#include "binary_trees.h"

bst_t *bst_create(int value);

/**
 * bst_insert - inserts a value in a Binary Search Tree
 *
 * @tree: a double pointer to the root node of the BST to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *parent, *current;

	new_node = bst_create(value); /* new node */

	/* if tree is null meaning no node in root */
	if (*tree == NULL)
	{
		*tree = new_node; /* becomes root */
		return (new_node); /* return new node */
	}

	parent = NULL; /* initialize to null */
	current = *tree; /* current points to root */

	while (current) /* traverse through tree */
	{
		if (value == current->n) /* value is already present */
		{
			free(new_node); /* free new node */
			return (NULL);
		}

		if (value < current->n) /* value is less than current */
		{
			parent = current; /* current node becomes parent node */
			current = current->left; /* go to left subtree so while loop runs again */
		}

		else /* value is greater than current */
		{
			parent = current; /* current node becomes parent node */
			current = current->right; /* go to right subtree so while loop runs again */
		}
	}

	/* link parent and new node */
	if (value < parent->n) /* value is less than parent */
	{
		parent->left = new_node; /* parent left points to new node */
		new_node->parent = parent; /* child points to parent */
	}

	else /* value is greater than parent */
	{
		parent->right = new_node; /* parent right points to new node */
		new_node->parent = parent; /* child points to parent */
	}

	return (new_node);
}

/**
 * bst_create - creates a bst node
 *
 * @value: value to store in node
 *
 * Return: a pointer to the node created
 */

bst_t *bst_create(int value)
{
	bst_t *node = NULL;

	node = malloc(sizeof(bst_t)); /* create location in memory */
	if (node == NULL) /* malloc fails */
	{
		return (NULL);
	}

	node->n = value; /* assign value to node */
	node->parent = NULL; /* parent set to null */
	node->left = node->right = NULL; /* left and right set to null */

	return (node); /* return node created */
}
