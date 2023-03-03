#include "binary_trees.h"

int tree_depth(const binary_tree_t *tree);

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 *
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 *
 * Return: a pointer to the lowest common ancestor of two nodes
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				const binary_tree_t *second)
{
	int first_depth, second_depth;

	/* check if first or second node is NULL */
	if (first == NULL || second == NULL)
	{
		return (NULL);
	}

	first_depth = tree_depth(first); /* find depth of first node */
	second_depth = tree_depth(second); /* find depth of second node */

	/* move up first until they are on the same level */
	while (first_depth > second_depth)
	{
		first = first->parent;
		first_depth--;
	}

	/* move up second until they are on the same level */
	while (second_depth > first_depth)
	{
		second = second->parent;
		second_depth--;
	}

	/* move up both nodes together until a common ancestor is met */
	while (first && second && first != second)
	{
		first = first->parent;
		second = second->parent;
	}

	return ((binary_tree_t *)first); /* return first */
}

/**
 * tree_depth - measures the depth of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the depth
 *
 * Return: tree depth, 0 if tree is NULL
 */

int tree_depth(const binary_tree_t *tree)
{
	int depth = 1;

	/* Base case */
	if (tree == NULL || tree->parent == NULL)
	{
		return (0);
	}

	/* increment depth for every recursive call to parent */
	depth += tree_depth(tree->parent);

	return (depth); /* return depth of tree */
}
