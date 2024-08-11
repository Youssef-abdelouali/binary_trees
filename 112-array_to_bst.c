#include "binary_trees.h"

/**
 * array_to_bst - Creates a Binary Search Tree (BST) from an array of integers.
 * @array: A pointer to the first element of the array to be converted into a BST.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the created BST, or NULL if an error occurs.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t current_index, check_index;

	if (array == NULL)
		return (NULL);

	for (current_index = 0; current_index < size; current_index++)
	{
		/* Check if the current value is a duplicate */
		for (check_index = 0; check_index < current_index; check_index++)
		{
			if (array[check_index] == array[current_index])
				break;
		}
		/* If the value is not a duplicate, insert it into the BST */
		if (check_index == current_index)
		{
			if (bst_insert(&tree, array[current_index]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
