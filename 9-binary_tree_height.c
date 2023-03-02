#include "binary_trees.h"

size_t max_height(size_t left, size_t right);

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the height
 *
 * Return: tree height, 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height, height;

	/* Base case */
	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
	{
		return (0);
	}

	/* recursive call to left subtree */
	left_height = binary_tree_height(tree->left);
	/* recursive call to right subtree */
	right_height = binary_tree_height(tree->right);
	/* call max_height to get higher of left or right subtree */
	height = 1 + max_height(left_height, right_height);

	return (height); /* return height of tree */
}

/**
 * max_height - compares the height of left and right tree
 *
 * @left: left tree
 * @right: right tree
 *
 * Return: the height of the higher of both trees
 */

size_t max_height(size_t left, size_t right)
{
	if (left > right) /* left tree  is higher */
	{
		return (left);
	}

	else /* right tree is higher */
	{
		return (right);
	}
}
