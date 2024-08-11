#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child
 *                            of a given parent node in a binary tree.
 * @parent: Pointer to the parent node where the right-child will be inserted.
 * @value: The value to store in the new node.
 *
 * Return: Pointer to the newly created node, or NULL on failure.
 *
 * Description: If the parent node already has a right-child, the new node
 *              takes its place, and the old right-child becomes the
 *              right-child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    /* Ensure the parent node is not NULL */
    if (!parent)
        return (NULL);

    /* Allocate memory and initialize the new node */
    binary_tree_t *new_node = binary_tree_node(parent, value);

    /* Check if memory allocation was successful */
    if (!new_node)
        return (NULL);

    /* If the parent already has a right child, adjust the pointers */
    if (parent->right)
    {
        new_node->right = parent->right;
        parent->right->parent = new_node;
    }

    /* Assign the new node as the right child of the parent */
    parent->right = new_node;

    return (new_node);
}
