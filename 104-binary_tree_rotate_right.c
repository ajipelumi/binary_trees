#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 *
 * @tree: a pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	/* if tree or tree left is NULL, rotation can not happen */
	if (tree == NULL || tree->left == NULL)
	{
		return (tree);
	}

	/* get new root */
	new_root = tree->left;
	/* previous root left now points to new root right */
	tree->left = new_root->right;

	/* if new root right */
	if (new_root->right)
	{
		/* new root right has new parent */
		new_root->right->parent = tree;
	}

	/* new root right now points to previous root */
	new_root->right = tree;
	/* previous root parent now points to new root */
	tree->parent = new_root;
	/* new root parent is now null */
	new_root->parent = NULL;

	return (new_root); /* return new root */
}
