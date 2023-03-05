#include "binary_trees.h"

bst_t *min_value(bst_t *tree);

/**
 * bst_remove - removes a node from a Binary Search Tree
 *
 * @root: a pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 *
 * Return: a pointer to the new root node of the tree
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *node;

	if (root == NULL) /* if root is null */
	{
		return (NULL);
	}
	if (value < root->n) /* value is less than value at root */
	{
		root->left = bst_remove(root->left, value);
	}
	else if (value > root->n) /* value is greater than value at root */
	{
		root->right = bst_remove(root->right, value);
	}
	else /* value to be deleted is met */
	{
		if (root->left == NULL && root->right == NULL) /* value has no child */
		{
			free(root); /* free root */
			root = NULL; /* root is a dangling pointer so set it to null */
		}
		else if (root->left == NULL) /* value has no left child */
		{
			temp = root;
			root = root->right;
			free(temp);
		}
		else if (root->right == NULL) /* value has no right child */
		{
			temp = root;
			root = root->left;
			free(temp);
		}
		else /* value has both left and right children */
		{
			node = min_value(root->right); /* get the in order successor */
			root->n = node->n; /* replace predecessor with successor */
			root->right = bst_remove(root->right, node->n); /* delete successor */
		}
	}
	return (root); /* return root */
}

/**
 * min_value - get the minimum value in a subtree
 *
 * @tree: a pointer to the subtree to be checked
 *
 * Return: a pointer to the minimum value in the subtree
 */

bst_t *min_value(bst_t *tree)
{
	/* if tree is null */
	if (tree == NULL)
	{
		return (NULL);
	}

	while (tree->left) /* loop through left side */
	{
		tree = tree->left; /* go to left most node */
	}

	return (tree); /* return node as minimum value */
}
