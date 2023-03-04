#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue = malloc(sizeof(*queue) * 1024);
	int head = 0, tail = 0, size = 0, flag = 0, i;

	if (tree == NULL) /* if tree is NULL */
		return (0);
	if (queue == NULL) /* malloc fails */
		return (0);
	queue[0] = (binary_tree_t *) tree; /* add root node to queue */
	tail = size = 1; /* tail and size increases by 1 */
	while (head < size) /* iterate over queue */
	{
		for (i = head; i < size; i++)
		{
			if (queue[i]->left) /* check if a left child exists */
			{
				if (flag == 1) /* implies that the right of the prev node is not full */
				{
					free(queue);
					return (0);
				}
				queue[tail++] = queue[i]->left; /* last item now points to left */
			}
			else /* no left child */
				flag = 1;
			if (queue[i]->right) /* check if a right child exists */
			{
				if (flag == 1) /* implies that the left of the prev node is not full */
				{
					free(queue);
					return (0);
				}
				queue[tail++] = queue[i]->right; /* last item now points to right */
			}
			else /* no right child */
				flag = 1;
		}
		head = size, size = tail;
	}
	free(queue); /* free queue */
	return (flag); /* return flag */
}
