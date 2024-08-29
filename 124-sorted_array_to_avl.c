#include "binary_trees.h"

/**
 * _sorted_array_to_avl - Helper function for creating an AVL tree from a sorted array
 * @array: Input array of integers
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray
 * @parent: Pointer to the parent node
 * Return: Pointer to the newly created AVL node, or NULL on failure
 */
avl_t *_sorted_array_to_avl(int *array, int start, int end, avl_t *parent)
{
	avl_t *node;
	int middle;

	if (start > end)
		return (NULL);
	middle = (start + end) / 2;
	node = calloc(1, sizeof(avl_t));
	if (!node)
		return (NULL);
	node->n = array[middle];
	node->parent = parent;
	node->left = _sorted_array_to_avl(array, start, middle - 1, node);
	node->right = _sorted_array_to_avl(array, middle + 1, end, node);
	return (node);
}

/**
 * sorted_array_to_avl - Converts a sorted array into an AVL tree
 * @array: Input array of integers
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);
	return (_sorted_array_to_avl(array, 0, size - 1, NULL));
}
