#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: If tree is NULL, the function returns 0. Otherwise, it returns the depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* If the node has a parent, add 1 to the depth and continue recursively */
    if (tree->parent)
        return (1 + binary_tree_depth(tree->parent));

    /* If the node is the root, the depth is 0 */
    return (0);
}
