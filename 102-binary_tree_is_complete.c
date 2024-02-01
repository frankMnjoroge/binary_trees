#include "binary_trees.h"

/**
 * bin_tr_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is not complete
 *         0 if tree is NULL
 */
int bin_tr_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = bin_tr_size(tree);

	return (btic_help(tree, 0, size));
}

/**
 * btic_help - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * @index: node index to check
 * @size: number of nodes in the tree
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is not complete
 *         0 if tree is NULL
 */
int btic_help(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (btic_help(tree->left, 2 * index + 1, size) &&
		btic_help(tree->right, 2 * index + 2, size));
}

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

	return (bin_tr_size(tree->left) +
		bin_tr_size(tree->right) + 1);
}
