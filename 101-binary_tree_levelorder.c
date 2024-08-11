#include "binary_trees.h"

/**
 * binary_tree_height - Calculates the height of a binary tree.
 * @tree: A pointer to the root node of the tree whose height is to be measured.
 *
 * Return: The height of the tree. Returns 0 if the tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height >= right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_level - Applies a function to all nodes at a specific level of a binary tree.
 * @tree: A pointer to the root of the tree.
 * @level: The level in the tree at which the function is to be applied.
 * @func: The function to apply to each node at the specified level.
 *
 * Return: void
 */
void binary_tree_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		binary_tree_level(tree->left, level - 1, func);
		binary_tree_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - Performs a level-order traversal of a binary tree.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node. The node value is passed as an argument to this function.
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, index;

	if (tree == NULL || func == NULL)
		return;

	height = binary_tree_height(tree);
	for (index = 1; index <= height; index++)
		binary_tree_level(tree, index, func);
}

