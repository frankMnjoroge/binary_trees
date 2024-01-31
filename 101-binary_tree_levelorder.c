#include "binary_trees.h"

/**
 * bin_tr_levelorder - traverst a binary tree using level-order traverse
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 */
void bin_tr_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, maxlevel;

	if (!tree || !func)
		return;

	maxlevel = bin_tr_height(tree) + 1;

	for (level = 1; level <= maxlevel; level++)
		btlo_help(tree, func, level);
}

/**
 * btlo_help - goes through a binary tree using post-order traverse
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 * @level: the level of the tree to call func upon
 */
void btlo_help(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		btlo_help(tree->left, func, level - 1);
		btlo_help(tree->right, func, level - 1);
	}
}

/**
 * bin_tr_height - measures the height of a binary tree
 * @tree: tree to measure the height of
 *
 * Return: height of the tree
 *         0 if tree is NULL
 */
size_t bin_tr_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + bin_tr_height(tree->left) : 0;
	height_r = tree->right ? 1 + bin_tr_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
