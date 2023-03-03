#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree (level-order traversal)
 *
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 *
 * Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue = NULL;
	int head, tail, size, i;

	/* if tree or function to be called is NULL */
	if (tree == NULL || func == NULL)
	{
		return;
	}

	queue = malloc(sizeof(*queue) * 1024); /* create queue to store tree items */
	if (queue == NULL) /* malloc fails */
	{
		return;
	}
	head = tail = size = 0; /* initialize to zero */
	queue[0] = (binary_tree_t *) tree; /* add root node to queue */
	tail = size = 1; /* tail and size increases by 1 */

	while (head < size) /* use FIFO to print every queue item */
	{
		for (i = head; i < size; i++)
		{
			func(queue[i]->n); /* call print function */
			if (queue[i]->left) /* check if a left child exists */
			{
				queue[tail] = queue[i]->left; /* last item in queue now points to left */
				tail++; /* tail increases */
			}
			if (queue[i]->right) /* check if a right child exists */
			{
				queue[tail] = queue[i]->right; /* last item in queue now points to right */
				tail++; /* tail increases */
			}
		}
		/* head becomes size which means that child nodes have been added to queue */
		head = size;
		/* size becomes tail which means the number of items in the queue */
		size = tail;
	}
	free(queue); /* free queue */
}
