#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 *
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search in the tree
 *
 * Return: a pointer to the node containing a value equals to value
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *current;

	/* if tree is null */
	if (tree == NULL)
	{
		return (NULL);
	}

	current = (bst_t *) tree; /* current points to root */

	while (current) /* traverse through tree */
	{
		if (value == current->n) /* searched value found */
		{
			return (current);
		}

		if (value < current->n) /* value is less than current */
		{
			current = current->left; /* go to left subtree to search */
		}

		if (value > current->n) /* value is greater than current */
		{
			current = current->right; /* go to right subtree to search */
		}
	}

	return (NULL); /* returns null as value is not found */
}
