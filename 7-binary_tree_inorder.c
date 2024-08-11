#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverses a binary tree in an in-order manner.
 * @tree: A pointer to the root node of the tree to be traversed.
 * @func: A pointer to the function that is called for each node's value.
 *
 * Description: This function visits the nodes of the binary tree in the
 *              in-order sequence: it first recursively visits the left
 *              subtree, then processes the current node, and finally
 *              traverses the right subtree.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
    /* Check if the tree and function pointers are not NULL */
    if (tree == NULL || func == NULL)
        return;

    /* Recursively traverse the left subtree */
    if (tree->left != NULL)
        binary_tree_inorder(tree->left, func);

    /* Apply the function to the current node's value */
    func(tree->n);

    /* Recursively traverse the right subtree */
    if (tree->right != NULL)
        binary_tree_inorder(tree->right, func);
}
