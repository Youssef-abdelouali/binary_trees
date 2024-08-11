#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_is_leaf - Checks if a node is a leaf.
 * @node: Pointer to the node to check.
 *
 * Return: 1 if node is a leaf, 0 otherwise. If node is NULL, return 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height of.
 *
 * Return: The height of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	if (left_height >= right_height)
		return (1 + left_height);
	return (1 + right_height);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	const binary_tree_t *left_child, *right_child;

	if (tree == NULL)
		return (1);
	left_child = tree->left;
	right_child = tree->right;
	if (binary_tree_is_leaf(tree))
		return (1);
	if (left_child == NULL || right_child == NULL)
		return (0);
	if (binary_tree_height(left_child) == binary_tree_height(right_child))
	{
		if (binary_tree_is_perfect(left_child) && binary_tree_is_perfect(right_child))
			return (1);
	}
	return (0);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if complete, 0 otherwise. If tree is NULL, return 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t left_height, right_height;
	const binary_tree_t *left_child, *right_child;

	if (tree == NULL)
		return (0);
	if (binary_tree_is_leaf(tree))
		return (1);
	left_child = tree->left;
	right_child = tree->right;
	left_height = binary_tree_height(left_child);
	right_height = binary_tree_height(right_child);
	if (left_height == right_height)
	{
		if (binary_tree_is_perfect(left_child) && binary_tree_is_complete(right_child))
			return (1);
	}
	else if (left_height == right_height + 1)
	{
		if (binary_tree_is_complete(left_child) && binary_tree_is_perfect(right_child))
			return (1);
	}
	return (0);
}
