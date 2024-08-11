#include "binary_trees.h"

/**
 * binary_tree_uncle - Retrieves the uncle of a given node in a binary tree.
 * @node: A pointer to the node whose uncle is to be found.
 *
 * Return: If the node is NULL or lacks an uncle, returns NULL.
 *         If the node has an uncle, returns a pointer to the uncle node.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || 
	    node->parent == NULL || 
	    node->parent->parent == NULL)
	{
		return (NULL);
	}

	/* Check if the parent is the left child of the grandparent */
	if (node->parent->parent->left == node->parent)
	{
		/* Return the right child of the grandparent as the uncle */
		return (node->parent->parent->right);
	}

	/* Otherwise, return the left child of the grandparent as the uncle */
	return (node->parent->parent->left);
}
