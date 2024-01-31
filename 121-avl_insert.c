#include "binary_trees.h"

/**
 * r_ins_node - node value instertion in a AVL.
 * @tree: type **pointer of root node of the AVL tree struct.
 * @parent: parent node of struct AVL.
 * @new: type**pointer left or right insertion.
 * @nval: insertion value of the AVL.
 * Return: pointer to the new root after insertion otherwise NULL
 */
avl_t *r_ins_node(avl_t **tree, avl_t *parent, avl_t **new, int nval)
{
	int bval;

	if (*tree == NULL)
		return (*new = bin_tr_node(parent, nval));
	if ((*tree)->n > nval)
	{
		(*tree)->left = r_ins_node(&(*tree)->left, *tree, new, nval);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < nval)
	{
		(*tree)->right = r_ins_node(&(*tree)->right, *tree, new, nval);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}
	bval = bin_tr_balance(*tree);
	if (bval > 1 && (*tree)->left->n > nval)
	{
		*tree = bin_tr_rotate_right(*tree);
	}
	else if (bval > 1 && (*tree)->left->n < nval)
	{
		(*tree)->left = bin_tr_rotate_left((*tree)->left);
		*tree = bin_tr_rotate_right(*tree);
	}
	else if (bval < -1 && (*tree)->right->n < nval)
	{
		*tree = bin_tr_rotate_left(*tree);
	}
	else if (bval < -1 && (*tree)->right->n > nval)
	{
		(*tree)->right = bin_tr_rotate_right((*tree)->right);
		*tree = bin_tr_rotate_left(*tree);
	}
	return (*tree);
}
/**
 * avl_ins - inserts a value into an AVL tree.
 * @tree: type **pointer to the root node of the AVL tree to insert into.
 * @value: value to store in the node to be inserted
 * Return: inserted node, or NULL if fails.
 */
avl_t *avl_ins(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (*tree == NULL)
	{
		*tree = bin_tr_node(NULL, value);
		return (*tree);
	}
	r_ins_node(tree, *tree, &new, value);
	return (new);
}
