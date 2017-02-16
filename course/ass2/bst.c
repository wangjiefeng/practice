#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "bst.h"

/*
 * Creates a new node from a given value, allocating heap memory for it.
 */
node_t* make_tree(int val) {
  node_t* new_tree = malloc(sizeof(node_t));
  new_tree->val = val;
  new_tree->left = NULL;
  new_tree->right = NULL;
  return new_tree;
}

/*
 * Inserts a new value into a given binary search tree, allocating heap memory
 * for it.
 */
node_t* insert(int val, node_t* cur_root) {
  /* YOUR CODE HERE */
  assert(cur_root != NULL);
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  node_t *p = cur_root;
  new_node->val = val;
  new_node->left = new_node->right = NULL;
  while(p) {
  	if (val > p->val) {
  		if (p->right)
  			p = p->right;
  		else {
  			p->right = new_node;
  			break;
  		}
  	}
  	else {
  		if (p->left)
  			p = p->left;
  		else {
  			p->left = new_node;
  			break;
  		}
  	}
  }
  return cur_root;
}

bool find_val(int val, node_t* root) {
  /* YOUR CODE HERE */
  assert(root != NULL);
  node_t *p = root;
  while(p) {
  	if (val > p->val)
  		p = p->right;
  	else if (val < p->val)
  		p = p->left;
  	else return TRUE;
  }
  return FALSE;
}

/*
 * Given a pointer to the root, frees the memory associated with an entire tree.
 */
void delete_bst(node_t* root) {
  /* YOUR CODE HERE */
  node_t *p = root;
  if (!p)
  	return;
  delete_bst(p->left);
  delete_bst(p->right);
  free(p);
}

/* Given a pointer to the root, prints all o fthe values in a tree. 先根序*/
void print_bst(node_t* root) {
  if (root != NULL) {
    printf("%d ", root->val);
    print_bst(root->left);
    print_bst(root->right);
  }
  return;
}
