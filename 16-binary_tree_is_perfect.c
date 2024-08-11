#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - Determines if a node is a leaf in a binary tree.
 * @node: A pointer to the node to evaluate.
 *
 * Return: Returns 1 if the node is a leaf (has no children), otherwise returns 0.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - Computes the depth of a node within a binary tree.
 * @tree: A pointer to the node whose depth is to be calculated.
 *
 * Return: The depth of the given node.
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Finds and returns a leaf node from the binary tree.
 * @tree: A pointer to the root node of the tree to search for a leaf.
 *
 * Return: A pointer to the first encountered leaf node.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Recursively checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to evaluate.
 * @leaf_depth: The depth of one leaf node in the tree.
 * @level: The current level of the node being evaluated.
 *
 * Return: Returns 1 if the tree is perfect, otherwise returns 0.
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Determines if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: Returns 0 if the tree is NULL or not perfect.
 *         Returns 1 if the tree is perfect.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
