#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    size_t left_height = 0, right_height = 0;

    /* Calculate the height of the left subtree */
    if (tree->left)
        left_height = 1 + binary_tree_height(tree->left);
    
    /* Calculate the height of the right subtree */
    if (tree->right)
        right_height = 1 + binary_tree_height(tree->right);
    
    /* Return the maximum of the two heights */
    return (left_height > right_height) ? left_height : right_height;
}
