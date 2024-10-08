#include "binary_trees.h"

/**
 * binary_tree_balance - Computes the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: The balance factor of the tree. If tree is NULL, returns 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lef_t = 0, righ_t = 0;

		lef_t = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		righ_t = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((lef_t > righ_t) ? lef_t : righ_t);
	}
	return (0);
}
