#include "binary_trees.h"

/**
 * binary_tree_preorder - goes through a binary tree (pre-order traversal)
 *
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 *
 * Return: void
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	/* tree or function to be called is not NULL */
	if (tree != NULL && func != NULL)
	{
		/* pre-order traversal means we call function before recursion */
		func(tree->n);
		/* recursion on the left side of tree */
		binary_tree_preorder(tree->left, func);
		/* recursion on the right side of tree */
		binary_tree_preorder(tree->right, func);
	}
}
