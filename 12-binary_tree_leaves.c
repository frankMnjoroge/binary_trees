#include "binary_trees.h"

/**
 * bin_tr_leaves - counts the leaves in a binary tree
 * @tree: tree to count the leaves from
 *
 * Return: number of leaves
 *         0 if tree is NULL
 */
size_t bin_tr_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (bin_tr_leaves(tree->left) + bin_tr_leaves(tree->right));
}
