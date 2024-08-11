#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes in a binary tree.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: If there is no common ancestor, returns NULL.
 *         Otherwise, returns a pointer to the lowest common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *parent_first, *parent_second;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	parent_first = first->parent;
	parent_second = second->parent;

	/* If the first node's parent is the same as the second node, or if the second node has no parent, recurse with the first node and the second node's parent */
	if (first == parent_second || !parent_first || (!parent_first->parent && parent_second))
		return (binary_trees_ancestor(first, parent_second));

	/* If the second node's parent is the same as the first node, or if the first node has no parent, recurse with the second node and the first node's parent */
	else if (second == parent_first || !parent_second || (!parent_second->parent && parent_first))
		return (binary_trees_ancestor(parent_first, second));

	/* Recurse with the parents of both nodes */
	return (binary_trees_ancestor(parent_first, parent_second));
}
