#include "binary_trees.h"

/**
 * binary_tree_sibling - Determines the sibling of a specified node in a binary tree.
 * @node: A pointer to the node whose sibling is to be identified.
 *
 * Return: Returns NULL if the node is NULL or if the node has no sibling.
 *         If a sibling exists, returns a pointer to the sibling node.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* Check if the node is the left child, return the right child as sibling */
	if (node->parent->left == node)
		return (node->parent->right);

	/* Otherwise, return the left child of the parent as the sibling */
	return (node->parent->left);
}
