#include "binary_trees.h"
#include <limits.h>

int is_bst(const binary_tree_t *tree, int min_val, int max_val);

/**
 * binary_tree_is_bst -  checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	/* if tree is null */
	if (tree == NULL)
	{
		return (0);
	}

	/* set the initial minimum and maximum values */
	/* these values are the min and max possible values of tree->n (int) */
	return (is_bst(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst -  checks if a binary tree is a valid Binary Search Tree
 *
 * @tree: a pointer to the root node of the tree to check
 * @min_val: minimum possible value
 * @max_val: maximum possible value
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */

int is_bst(const binary_tree_t *tree, int min_val, int max_val)
{
	int left, right;

	/* if tree is null */
	if (tree == NULL)
	{
		/**
		 * when tree is null, end of tree is met
		 * meaning every left subtree is lesser and
		 * right subtree is greater than tree, 1 is
		 * returned to handle this case
		 */
		return (1);
	}

	/**
	 * if current root value is lesser than minimum value
	 * or greater than maximum value, tree is not a
	 * binary search tree, 0 is returned
	 */
	if (tree->n < min_val || tree->n > max_val)
	{
		return (0);
	}

	left = (is_bst(tree->left, min_val, tree->n - 1));
	right = (is_bst(tree->right, tree->n + 1, max_val));
	return (left && right);
}
