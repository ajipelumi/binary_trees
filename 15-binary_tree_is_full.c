#include "binary_trees.h"

int tree_is_full(const binary_tree_t *tree);

/**
 * binary_tree_is_full - checks if a binary tree is full
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is full, 0 if tree is NULL
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int full;

	/* check if tree is NULL */
	if (tree == NULL)
	{
		return (0);
	}

	full = tree_is_full(tree); /* check if tree is full */

	return (full);
}

/**
 * tree_is_full - checks if tree is full
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is full, 0 otherwise
 */

int tree_is_full(const binary_tree_t *tree)
{
	int left_full, right_full;

	/* Base case */
	if (tree == NULL)
	{
		/* return 1 because an empty tree is considered a full tree */
		return (1);
	}

	left_full = tree_is_full(tree->left); /* check the left subtree */
	right_full = tree_is_full(tree->right); /* check the right subtree */

	/* left and right both exist */
	if (tree->left != NULL && tree->right != NULL)
	{
		return (left_full && right_full);
	}

	/* left and right do not exist */
	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}

	/* left or right exists */
	else
	{
		return (0);
	}
}
