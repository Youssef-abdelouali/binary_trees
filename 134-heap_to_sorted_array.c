#include "binary_trees.h"
#include<stdlib.h>

/**
 * heap_to_sorted_array - Transforms a Max Binary Heap into a sorted array of integers
 * @heap: Pointer to the root node of the Max Binary Heap to be converted
 * @size: Pointer to a variable where the size of the resulting array will be stored
 * Return: Pointer to a sorted array of integers, or NULL if allocation fails
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *sorted_array;
	int value, index = 0;
	size_t heap_size;

	if (!heap)
		return (NULL);
	heap_size = binary_tree_size(heap);
	*size = heap_size;
	sorted_array = malloc(heap_size * sizeof(int));
	if (!sorted_array)
		return (NULL);
	while (heap)
	{
		value = heap_extract(&heap);
		sorted_array[index] = value;
		index++;
	}
	return (sorted_array);
}
