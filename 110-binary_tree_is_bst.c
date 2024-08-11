#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Recursively verifies if a binary tree adheres to BST properties.
 * @node: A pointer to the current node being checked.
 * @lower_bound: The lowest value that the current node can have.
 * @upper_bound: The highest value that the current node can have.
 *
 * Return: 1 if the subtree rooted at node is a valid BST, otherwise 0.
 */
int is_bst_helper(const binary_tree_t *node, int lower_bound, int upper_bound)
{
	if (node != NULL)
	{
		if (node->n < lower_bound || node->n > upper_bound)
			return (0);
		return (is_bst_helper(node->left, lower_bound, node->n - 1) &&
			is_bst_helper(node->right, node->n + 1, upper_bound));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Determines if a binary tree is a valid binary search tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid BST, otherwise 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
