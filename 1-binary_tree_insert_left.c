#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of a parent node
 *                           in a binary tree.
 * @parent: Pointer to the node to insert the left-child under.
 * @value: The value to store in the new node.
 *
 * Return: Pointer to the newly created node, or NULL on failure.
 *
 * Description: If the parent node already has a left-child, the new node
 *              will take its place, and the old left-child will become
 *              the left-child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    /* Check if the parent node is NULL */
    if (!parent)
        return (NULL);

    /* Create a new node with the specified value */
    binary_tree_t *new_node = binary_tree_node(parent, value);

    /* Return NULL if memory allocation fails */
    if (!new_node)
        return (NULL);

    /* If the parent already has a left child, update pointers */
    if (parent->left)
    {
        new_node->left = parent->left;
        parent->left->parent = new_node;
    }

    /* Set the new node as the left child of the parent */
    parent->left = new_node;

    return (new_node);
}
