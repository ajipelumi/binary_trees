#include "binary_trees.h"

int tree_height(binary_tree_t *tree);
int max_height(int left, int right);
int tree_size(binary_tree_t *tree);

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, 0 if tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left, right, left_size, right_size;

	/* check if tree is NULL */
	if (tree == NULL)
	{
		return (0);
	}

	left = tree_height(tree->left); /* get height of left subtree */
	right = tree_height(tree->right); /* get height of right subtree */

	/* get number of nodes in the left */
	left_size = tree_size(tree->left);
	/* get number of nodes in the right */
	right_size = tree_size(tree->right);

	/* left and right subtrees are equal */
	if (left == right && left_size == right_size)
	{
		return (1);
	}
	else /* left and right subtrees are not equal */
	{
		return (0);
	}
}

/**
 * tree_height - measures the height of a tree
 *
 * @tree: a pointer to the root node of the tree to measure the height
 *
 * Return: tree height, -1 if tree is NULL
 */

int tree_height(binary_tree_t *tree)
{
	int left_height, right_height, height;

	/* if tree is NULL, height is -1 */
	if (tree == NULL)
	{
		return (-1);
	}

	/* if tree does not have children, height is 0 */
	if (tree->left == NULL && tree->right == NULL)
	{
		return (0);
	}

	/* recursive call to left subtree */
	left_height = tree_height(tree->left);

	/* recursive call to right subtree */
	right_height = tree_height(tree->right);

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

int max_height(int left, int right)
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

/**
 * tree_size - measures the size of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the size
 *
 * Return: tree size, 0 if tree is NULL
 */

int tree_size(binary_tree_t *tree)
{
	int size = 1;

	/* Base case */
	if (tree == NULL)
	{
		return (0);
	}

	/* increment size for every recursive call to left subtree */
	size += tree_size(tree->left);
	/* increment size for every recursive call to right subtree */
	size += tree_size(tree->right);

	return (size); /* return size of tree */
}
