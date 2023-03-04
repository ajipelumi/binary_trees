#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 *
 * @tree: a pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	/* if tree or tree right is NULL, rotation can not happen */
	if (tree == NULL || tree->right == NULL)
	{
		return (tree);
	}

	/* get new root */
	new_root = tree->right;
	/* previous root left now points to new root left */
	tree->right = new_root->left;

	/* if new root left */
	if (new_root->left)
	{
		/* new root left has new parent */
		new_root->left->parent = tree;
	}

	/* new root left now points to previous root */
	new_root->left = tree;
	/* previous root parent now points to new root */
	tree->parent = new_root;
	/* new root parent is now null */
	new_root->parent = NULL;

	return (new_root); /* return new root */
}
