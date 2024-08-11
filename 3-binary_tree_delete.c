#include "binary_trees.h"

/**
 * binary_tree_delete - Recursively deletes an entire binary tree.
 * @tree: Pointer to the root node of the tree to delete.
 *
 * Description: This function performs a post-order traversal to
 *              delete each node of the binary tree.
 */
void binary_tree_delete(binary_tree_t *tree)
{
    if (!tree)
        return;

    /* Recursively delete the left and right subtrees */
    binary_tree_delete(tree->left);
    binary_tree_delete(tree->right);

    /* Free the current node */
    free(tree);
}
