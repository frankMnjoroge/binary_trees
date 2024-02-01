#include "binary_trees.h"

/**
 * bin_tr_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t bin_tr_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bin_tr_size(tree->left) + bin_tr_size(tree->right) + 1);
}
