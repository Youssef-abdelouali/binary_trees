#include "binary_trees.h"

/**
 * binary_tree_is_root - Determines if a given node is the root of a binary tree.
 * @node: Pointer to the node to evaluate.
 *
 * Return: 1 if the node is the root (i.e., it has no parent), otherwise 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
    /* Check if the node is NULL or has a parent */
    if (node == NULL)
        return (0);

    if (node->parent == NULL)
        return (1);

    return (0);
}
