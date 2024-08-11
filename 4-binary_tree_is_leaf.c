#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf in a binary tree.
 * @node: Pointer to the node to check.
 *
 * Return: 1 if the node is a leaf, otherwise 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
    /* A node is a leaf if it is not NULL and has no children */
    if (node && !node->left && !node->right)
        return (1);

    return (0);
}
