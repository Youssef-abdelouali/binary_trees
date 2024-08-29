#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in the @array.
 *
 * Return: A pointer to the root node of the created AVL tree, or NULL if it fails.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t index, duplicate_index;

	if (array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
	{
		for (duplicate_index = 0; duplicate_index < index; duplicate_index++)
		{
			if (array[duplicate_index] == array[index])
				break;
		}
		if (duplicate_index == index)
		{
			if (avl_insert(&tree, array[index]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
