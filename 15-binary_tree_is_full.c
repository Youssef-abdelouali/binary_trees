#include "binary_trees.h"

/**
 * is_full_recursive - Determines if a binary tree is full through recursive checks.
 * @tree: A pointer to the root node of the tree to evaluate.
 *
 * Return: Returns 0 if the tree is not full.
 *         Returns 1 if the tree is full.
 */
int is_full_recursive(const binary_tree_t *tree)
{
    if (tree != NULL)
    {
        if ((tree->left != NULL && tree->right == NULL) ||
            (tree->left == NULL && tree->right != NULL) ||
            is_full_recursive(tree->left) == 0 ||
            is_full_recursive(tree->right) == 0)
            return (0);
    }
    return (1);
}

/**
 * binary_tree_is_full - Evaluates if a binary tree is fully populated.
 * @tree: A pointer to the root node of the tree to evaluate.
 *
 * Return: Returns 0 if the tree is NULL or not fully populated.
 *         Returns 1 if the tree is fully populated.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (is_full_recursive(tree));
}
