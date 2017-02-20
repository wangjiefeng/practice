#include "bst.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

bst_t* make_tree(int size)
{
	bst_t *tree = (bst_t *)malloc(sizeof(bst_t));
	tree->size = size;
	tree->vals = (int *)malloc(size * sizeof(int));
	return tree;
}
/*
 * Initialize the binary search tree.
 * HINT: What should we initialize values to?  What requirements might we have
 * to add to the tree specification?
 */
void init_tree(bst_t* tree)
{
	assert(tree != NULL);
	int i = 0;
	while(i < tree->size) {
		tree->vals[i++] = -1;
	}
}

/*
 * Inserts a new value into a given tree.
 */
void insert(int val, bst_t* tree)
{
	assert(tree != NULL && tree->vals != NULL);
	int i = 0;
	while(i < tree->size && tree->vals[i] != -1) {
		if(val < tree->vals[i])
			i = 2 * i + 1;
		else
			i = 2 * i + 2;
	}
	tree->vals[i] = val;
}

bool find_val(int val, bst_t* tree)
{
	assert(tree != NULL && tree->vals != NULL);
	int i = 0;
	while(i < tree->size && tree->vals[i] != -1) {
		if(tree->vals[i] == val)
			return TRUE;
		if(val < tree->vals[i])
			i = 2 * i + 1;
		else
			i = 2 * i + 2;
	}
	return FALSE;
}

/*
 * Given a pointer to the root, frees the memory associated with an entire list.
 */
void delete_bst(bst_t* tree)
{
	assert(tree != NULL && tree->vals != NULL);
	free(tree->vals);
	tree->size = 0;
}

/* Given a pointer to the root, prints all of the values in a list. */
void print_bst(bst_t* tree)
{
	assert(tree != NULL && tree->vals != NULL);
	int i = 0;
	while(i < tree->size) {
		if(tree->vals[i] == -1) {
			i++;
			continue;
		}
		printf("%d ", tree->vals[i++]);
	}
}
