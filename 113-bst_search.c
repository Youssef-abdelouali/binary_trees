#include "binary_trees.h"

/**
 * bst_search - Searches for a specific value in a binary search tree.
 * @tree: A pointer to the root node of the BST where the search is performed.
 * @value: The value to be searched within the BST.
 *
 * Return: A pointer to the node containing the value if found, or NULL if
 *         the value is not present or the tree is NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		/* Check if the current node contains the value */
		if (tree->n == value)
			return ((bst_t *)tree);
		/* Search in the left subtree if the value is less than the current node's value */
		if (tree->n > value)
			return (bst_search(tree->left, value));
		/* Search in the right subtree if the value is greater than the current node's value */
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
