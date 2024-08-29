#include "binary_trees.h"

size_t calculate_height(const binary_tree_t *tree);
int calculate_balance(const binary_tree_t *tree);
avl_t *avl_insert_node(avl_t **tree, avl_t *parent,
		avl_t **new_node, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * calculate_height - Determines the height of a binary tree.
 * @tree: A pointer to the root node of the tree whose height is being measured.
 *
 * Return: If the tree is NULL, returns 0. Otherwise, returns the height of the tree.
 */
size_t calculate_height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t left_height = 0, right_height = 0;

		left_height = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		right_height = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((left_height > right_height) ? left_height : right_height);
	}
	return (0);
}

/**
 * calculate_balance - Computes the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree whose balance factor is being calculated.
 *
 * Return: If the tree is NULL, returns 0. Otherwise, returns the balance factor.
 */
int calculate_balance(const binary_tree_t *tree)
{
	return (tree != NULL ? calculate_height(tree->left) - calculate_height(tree->right) : 0);
}

/**
 * avl_insert_node - Recursively inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree.
 * @parent: The parent node of the current node being processed.
 * @new_node: A double pointer to store the newly inserted node.
 * @value: The value to be inserted into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL if the insertion fails.
 */
avl_t *avl_insert_node(avl_t **tree, avl_t *parent,
		avl_t **new_node, int value)
{
	int balance_factor;

	if (*tree == NULL)
		return (*new_node = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_node(&(*tree)->left, *tree, new_node, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_node(&(*tree)->right, *tree, new_node, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	balance_factor = calculate_balance(*tree);
	if (balance_factor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (balance_factor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (balance_factor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance_factor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree.
 * @value: The value to be inserted into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL if the insertion fails.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_node(tree, *tree, &new_node, value);
	return (new_node);
}
