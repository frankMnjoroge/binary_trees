#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <limits.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

/* binary_tree_print.c */
void bin_tr_print(const binary_tree_t *);

/* tasks */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *bin_tr_insert_left(binary_tree_t *parent, int value);
binary_tree_t *bin_tr_insert_right(binary_tree_t *parent, int value);
void bin_tr_delete(binary_tree_t *tree);
int bin_tr_is_leaf(const binary_tree_t *node);
int bin_tr_is_root(const binary_tree_t *node);
void bin_tr_preorder(const binary_tree_t *tree, void (*func)(int));
void bin_tr_inorder(const binary_tree_t *tree, void (*func)(int));
void bin_tr_postorder(const binary_tree_t *tree, void (*func)(int));
size_t bin_tr_height(const binary_tree_t *tree);
size_t bin_tr_depth(const binary_tree_t *tree);
size_t bin_tr_size(const binary_tree_t *tree);
size_t bin_tr_leaves(const binary_tree_t *tree);
size_t bin_tr_nodes(const binary_tree_t *tree);
int bin_tr_balance(const binary_tree_t *tree);
int bin_tr_is_full(const binary_tree_t *tree);
int bin_tr_is_perfect(const binary_tree_t *tree);
binary_tree_t *bin_tr_sibling(binary_tree_t *node);
binary_tree_t *bin_tr_uncle(binary_tree_t *node);

/* Advanced tasks */
binary_tree_t *bin_tr_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second);
void bin_tr_levelorder(const binary_tree_t *tree, void (*func)(int));
int bin_tr_is_complete(const binary_tree_t *tree);
binary_tree_t *bin_tr_rotate_left(binary_tree_t *tree);
binary_tree_t *bin_tr_rotate_right(binary_tree_t *tree);
int bin_tr_is_bst(const binary_tree_t *tree);
bst_t *bst_ins(bst_t **tree, int value);
bst_t *arr_to_bst(int *array, size_t size);
bst_t *bst_sch(const bst_t *tree, int value);
bst_t *bst_rem(bst_t *root, int value);
int bin_tr_is_avl(const binary_tree_t *tree);
avl_t *avl_ins(avl_t **tree, int value);
avl_t *arr_to_avl(int *array, size_t size);
avl_t *avl_rem(avl_t *root, int value);
avl_t *sort_arr_to_avl(int *array, size_t size);
int bin_tr_is_heap(const binary_tree_t *tree);
heap_t *heap_ins(heap_t **root, int value);
heap_t *arr_to_heap(int *array, size_t size);
int heap_ext(heap_t **root);
int *heap_to_sort_arr(heap_t *heap, size_t *size);

/* helper functions */
int _pow_recurs(int x, int y);
binary_tree_t *bta_help(binary_tree_t *root, const binary_tree_t *first,
			  const binary_tree_t *second);
void btlo_help(const binary_tree_t *tree, void (*func)(int), size_t level);
int btic_help(const binary_tree_t *tree, size_t index, size_t size);
int btib_help(const binary_tree_t *tree, int low, int hi);
bst_t *bst_mn_vl(bst_t *root);
int btia_help(const binary_tree_t *tree, int low, int hi);
int btih_help(const binary_tree_t *tree);
void sata_help(avl_t **root, int *array, size_t lo, size_t hi);

#endif
