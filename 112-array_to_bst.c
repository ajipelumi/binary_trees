#include "binary_trees.h"

bst_t *create_bst(int val);
bst_t *insert_bst(bst_t **node, int val);

/**
 * array_to_bst - builds a Binary Search Tree from an array
 *
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 *
 * Return: a pointer to the root node of the created BST, or NULL on failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *node, *root = NULL;
	size_t i;

	/* if array is null */
	if (array == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++) /* iterate through array and add node to tree*/
	{
		node = bst_insert(&root, array[i]);
	}

	(void)node; /* unused variable */
	return (root); /* return root node */
}

/**
 * insert_bst - inserts a value in a Binary Search Tree
 *
 * @node: a double pointer to the root node of the BST to insert the value
 * @val: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
 */

bst_t *insert_bst(bst_t **node, int val)
{
	bst_t *new_node, *parent, *current;

	new_node = create_bst(val); /* new node */

	/* if node is null meaning no node in root */
	if (*node == NULL)
	{
		*node = new_node; /* becomes root */
		return (new_node); /* return new node */
	}

	parent = NULL; /* initialize to null */
	current = *node; /* current points to root */

	while (current) /* traverse through node */
	{
		if (val == current->n) /* val is already present */
		{
			free(new_node); /* free new node */
			return (NULL);
		}

		if (val < current->n) /* val is less than current */
		{
			parent = current; /* current node becomes parent node */
			current = current->left; /* go to left subtree so while loop runs again */
		}

		else /* val is greater than current */
		{
			parent = current; /* current node becomes parent node */
			current = current->right; /* go to right subtree so while loop runs again */
		}
	}

	/* link parent and new node */
	if (val < parent->n) /* val is less than parent */
	{
		parent->left = new_node; /* parent left points to new node */
		new_node->parent = parent; /* child points to parent */
	}

	else /* val is greater than parent */
	{
		parent->right = new_node; /* parent right points to new node */
		new_node->parent = parent; /* child points to parent */
	}

	return (new_node);
}

/**
 * create_bst - creates a bst node
 *
 * @val: val to store in node
 *
 * Return: a pointer to the node created
 */

bst_t *create_bst(int val)
{
	bst_t *node = NULL;

	node = malloc(sizeof(bst_t)); /* create location in memory */
	if (node == NULL) /* malloc fails */
	{
		return (NULL);
	}

	node->n = val; /* assign val to node */
	node->parent = NULL; /* parent set to null */
	node->left = node->right = NULL; /* left and right set to null */

	return (node); /* return node created */
}
