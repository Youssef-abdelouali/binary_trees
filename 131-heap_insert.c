#include "binary_trees.h"
#include <stdlib.h>
#include <string.h>
#define INIT_NODE {0, NULL, NULL, NULL}

/**
 * swap_nodes - Swaps two nodes in a binary tree
 * @node1: First node
 * @node2: Second node
 * Return: Pointer to the root node
 */
bst_t *swap_nodes(bst_t *node1, bst_t *node2)
{
	bst_t temp_node = INIT_NODE;

	temp_node.n = node1->n;
	temp_node.parent = node1->parent;
	temp_node.left = node1->left;
	temp_node.right = node1->right;
	node1->parent = node2;
	node1->left = node2->left;
	node1->right = node2->right;
	if (node2->left)
		node2->left->parent = node1;
	if (node2->right)
		node2->right->parent = node1;

	node2->parent = temp_node.parent;
	if (temp_node.parent)
	{
		if (node1 == temp_node.parent->left)
			temp_node.parent->left = node2;
		else
			temp_node.parent->right = node2;
	}
	if (node2 == temp_node.left)
	{
		node2->left = node1;
		node2->right = temp_node.right;
		if (temp_node.right)
			temp_node.right->parent = node2;
	}
	else if (node2 == temp_node.right)
	{
		node2->right = node1;
		node2->left = temp_node.left;
		if (temp_node.left)
			temp_node.left->parent = node2;
	}
	while (node2->parent)
		node2 = node2->parent;
	return (node2);
}

/**
 * convert_to_base - Converts a number to a string in a given base
 * @number: Input number
 * @base: Base for conversion
 * @to_lowercase: Flag to indicate if hexadecimal values should be lowercase
 * Return: Resulting string
 */
char *convert_to_base(unsigned long int number, int base, int to_lowercase)
{
	static char *digits;
	static char buffer[50];
	char *ptr;

	digits = (to_lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = 0;
	do {
		*--ptr = digits[number % base];
		number /= base;
	} while (number);

	return (ptr);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the binary tree
 * Return: Number of nodes in the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * insert_node - Helper function to insert a node into the correct position in a heap
 * @root: Double pointer to the root of the max heap
 * @node: Node to be inserted
 */
void insert_node(heap_t **root, heap_t *node)
{
	heap_t *current;
	int size;
	unsigned int i;
	char *binary_representation;
	char direction;

	current = *root;
	size = binary_tree_size(current) + 1;
	binary_representation = convert_to_base(size, 2, 1);
	for (i = 1; i < strlen(binary_representation); i++)
	{
		direction = binary_representation[i];
		if (i == strlen(binary_representation) - 1)
		{
			if (direction == '1')
			{
				node->parent = current;
				current->right = node;
				break;
			}
			else if (direction == '0')
			{
				node->parent = current;
				current->left = node;
				break;
			}
		}
		if (direction == '1')
			current = current->right;
		else if (direction == '0')
			current = current->left;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root of the tree
 * @value: Value to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL, *result;

	if (!root)
		return (NULL);
	new_node = calloc(1, sizeof(heap_t));
	new_node->n = value;
	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}
	insert_node(root, new_node);
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		result = swap_nodes(new_node->parent, new_node);
		if (result)
			*root = result;
	}
	return (new_node);
}
