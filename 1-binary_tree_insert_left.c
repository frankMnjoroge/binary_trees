#include "binary_trees.h"

/**
 * binary_tree_insert_left -  inserts a node as the left-child of another node
 *
 * @parent: is a pointer to the node to insert the left-child in
 * @value:  is the value to store in the new node
 *
 * Description - If parent already has a left-child, the new node must
 *				take its place, and the old left-child must be set as
 *				the left-child of the new node.
 *
 * Return: a pointer to the created node, or NULL on failure or if
 *			parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);

	nw = malloc(sizeof(binary_tree_t));
	if (!nw)
		return (NULL);

	nw->n = value;
	nw->parent = parent;
	nw->right = NULL;
	nw->left = parent->left;
	parent->left = nw;
	if (nw->left)
		nw->left->parent = nw;
	return (nw);
}
