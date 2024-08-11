#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a binary tree using pre-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node's value.
 *
 * Description: The function `func` is applied to the value stored in each node
 *              during the pre-order traversal, which visits the root node first,
 *              followed by the left subtree, and then the right subtree.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (!tree || !func)
        return;

    /* Apply the function to the current node */
    func(tree->n);

    /* Traverse the left subtree */
    if (tree->left)
        binary_tree_preorder(tree->left, func);

    /* Traverse the right subtree */
    if (tree->right)
        binary_tree_preorder(tree->right, func);
}
