#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 *
 * @tree: a pointer to the root node of the tree to delete
 *
 * Return: void
 */

void binary_tree_delete(binary_tree_t *tree)
{
	/* base call */
	if (tree != NULL)
	{
		binary_tree_delete(tree->left); /* recursive call to left side */
		binary_tree_delete(tree->right); /* recursive call to right side */
		free(tree); /* free memory */
	}
}
