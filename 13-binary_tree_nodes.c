#include "binary_trees.h"

/**
 * binary_tree_nodes - count the nodes with at least 1 child in a binary tree
 *
 * @tree: a pointer to the root node of the tree to count the nodes
 *
 * Return: tree nodes, 0 if tree is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 1;

	/* Base case */
	if (tree == NULL)
	{
		return (0);
	}

	/* left or right point to at least a child */
	if (tree->left == NULL && tree->right == NULL)
	{
		return (0);
	}

	/* increment nodes for every recursive call to left subtree */
	nodes += binary_tree_nodes(tree->left);
	/* increment nodes for every recursive call to right subtree */
	nodes += binary_tree_nodes(tree->right);

	return (nodes); /* return nodes of tree */
}
