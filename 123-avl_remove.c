#include "binary_trees.h"

/**
 * bal - Adjusts the balance factor of an AVL tree
 * @tree: Pointer to the root of the tree to be balanced
 *
 * Description: This function checks the balance factor of an AVL tree 
 * and performs the necessary rotations to ensure the tree remains balanced.
 */
void bal(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	bval = binary_tree_balance((const binary_tree_t *)*tree);
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * successor - Finds the in-order successor of a node
 * @node: Pointer to the node whose successor is needed
 *
 * Description: This function finds the minimum value in the right 
 * subtree of the given node, which is the in-order successor.
 *
 * Return: The value of the in-order successor, or 0 if the node is NULL
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
}

/**
 * remove_type - Removes a node from a BST based on its children
 * @root: Pointer to the node to be removed
 *
 * Description: This function handles the removal of a node by considering
 * its children and reattaching the subtree if necessary.
 *
 * Return: 0 if the node has no children, or a non-zero value if it does
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove - Removes a node from a binary search tree (BST)
 * @root: Pointer to the root of the tree
 * @value: Value of the node to be removed
 *
 * Description: This function removes a node with the specified value from 
 * the BST and adjusts the tree accordingly.
 *
 * Return: Pointer to the new root of the tree after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root of the AVL tree
 * @value: Value of the node to be removed
 *
 * Description: This function removes a node with the specified value from 
 * the AVL tree, rebalances the tree if necessary, and returns the new root.
 *
 * Return: Pointer to the new root of the AVL tree after removal
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}
