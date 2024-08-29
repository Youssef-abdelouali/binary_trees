#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right child
 *                            of another node in a binary tree.
 * @parent: A pointer to the node where the right child will be inserted.
 * @value: The value to store in the newly created node.
 *
 * Return: If parent is NULL or an error occurs, returns NULL.
 *         Otherwise, returns a pointer to the newly created node.
 *
 * Description: If the parent node already has a right child, the new node
 *              replaces it, and the existing right child becomes the
 *              right child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
}
