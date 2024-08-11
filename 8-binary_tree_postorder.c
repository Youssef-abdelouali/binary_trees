#include "binary_trees.h"

/**
 * binary_tree_postorder - Performs a post-order traversal of a binary tree.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to execute for each node's value.
 *
 * Description: In post-order traversal, the function `func` is called on
 *              each node's value after recursively traversing the left
 *              and right subtrees. This means that the left subtree is
 *              visited first, then the right subtree, and finally the
 *              root node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    /* Return if the tree or function pointer is NULL */
    if (!tree || !func)
        return;

    /* Recursively traverse the left subtree */
    binary_tree_postorder(tree->left, func);

    /* Recursively traverse the right subtree */
    binary_tree_postorder(tree->right, func);

    /* Apply the function to the current node's value */
    func(tree->n);
}
