#include "binary_trees.h"

/**
 * sort_arr_to_avl - builds an AVL tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: number of elements in the array
 *
 * Return: a pointer to the root node of the created AVL tree
 *         NULL on failure
 */
avl_t *sort_arr_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t middle;

	if (!array)
		return (NULL);
	middle = (size - 1) / 2;
	tree = bin_tr_node(NULL, array[middle]);

	sata_help(&tree, array, -1, middle);
	sata_help(&tree, array, middle, size);

	return (tree);
}

/**
 * sata_help - helper that builds an AVL tree from an array
 * @root: double pointer to the root node of the subtree
 * @array: a pointer to the first element of the array to be converted
 * @lo: lower bound index
 * @hi: upper bound index
 */
void sata_help(avl_t **root, int *array, size_t lo, size_t hi)
{
	avl_t *new = NULL;
	size_t middle;

	if (hi - lo > 1)
	{
		middle = (hi - lo) / 2 + lo;
		new = bin_tr_node(*root, array[middle]);
		if (array[middle] > (*root)->n)
			(*root)->right = new;
		else if (array[middle] < (*root)->n)
			(*root)->left = new;
		sata_help(&new, array, lo, middle);
		sata_help(&new, array, middle, hi);
	}
}
