#include <stdlib.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = bin_tr_node(NULL, 98);

    root->left = bin_tr_node(root, 12);
    root->left->left = bin_tr_node(root->left, 6);
    root->left->right = bin_tr_node(root->left, 16);

    root->right = bin_tr_node(root, 402);
    root->right->left = bin_tr_node(root->right, 256);
    root->right->right = bin_tr_node(root->right, 512);

    bin_tr_print(root);
    return (0);
}
