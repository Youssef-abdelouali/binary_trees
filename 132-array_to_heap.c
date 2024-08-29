#include "binary_trees.h"

/**
 * array_to_heap - Constructs a Max Binary Heap from an array of integers
 * @array: The input array of integers
 * @size: The number of elements in the array
 * Return: Pointer to the root node of the created Max Binary Heap,
 * or NULL if the process fails
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t i = 0;
	bst_t *root = NULL;

	if (!array)
		return (NULL);
	while (i < size)
	{
		heap_insert(&root, array[i]);
		i++;
	}
	return (root);
}
