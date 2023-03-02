#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree (in-order traversal)
 *
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 *
 * Return: void
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	/* tree or function to be called is not NULL */
	if (tree != NULL && func != NULL)
	{
		/* recursion on the left side of tree */
		binary_tree_inorder(tree->left, func);
		/* in-order traversal means we call function before right recursion */
		func(tree->n);
		/* recursion on the right side of tree */
		binary_tree_inorder(tree->right, func);
	}
}
