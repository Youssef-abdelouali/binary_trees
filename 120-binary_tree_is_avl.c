#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);

/**
 * height - Calculates the height of a binary tree.
 * @tree: A pointer to the root node of the tree to determine the height.
 *
 * Return: If the tree is NULL, the function returns 0; otherwise, it returns the height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_height = 0, right_height = 0;

		left_height = tree->left ? 1 + height(tree->left) : 1;
		right_height = tree->right ? 1 + height(tree->right) : 1;
		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
}

/**
 * is_avl_helper - Verifies if a binary tree adheres to AVL tree properties.
 * @tree: A pointer to the root node of the tree being validated.
 * @lo: The minimum allowable value for the current node.
 * @hi: The maximum allowable value for the current node.
 *
 * Return: 1 if the tree satisfies AVL properties, otherwise 0.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t left_height, right_height, height_difference;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		left_height = height(tree->left);
		right_height = height(tree->right);
		height_difference = left_height > right_height ? left_height - right_height : right_height - left_height;
		if (height_difference > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Determines if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to be checked.
 *
 * Return: 1 if the tree is a valid AVL tree, otherwise 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
