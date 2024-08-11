#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the number of nodes in a binary tree that have at least one child.
 * @tree: A pointer to the root node of the tree to be analyzed.
 *
 * Return: The number of nodes with at least one child. If the tree is NULL, returns 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    size_t nodes = 0;

    /* Check if the current node exists */
    if (tree)
    {
        /* Count the current node if it has at least one child */
        if (tree->left || tree->right)
            nodes += 1;

        /* Recursively count nodes with children in the left subtree */
        nodes += binary_tree_nodes(tree->left);
        
        /* Recursively count nodes with children in the right subtree */
        nodes += binary_tree_nodes(tree->right);
    }

    return (nodes);
}
