#include "binary_trees.h"

/**
 * binary_tree_node.
 * @parent: A pointer to the parent of the node to create.
 * @value: The value to put in the new node.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *ne_w;

	ne_w = malloc(sizeof(binary_tree_t));
	if (ne_w == NULL)
		return (NULL);

	ne_w->n = value;
	ne_w->parent = parent;
	ne_w->left = NULL;
	ne_w->right = NULL;

	return (ne_w);
}
