#include <assert.h>
#include <stdio.h>
#include "bst.h"

int main() {
  /* Insert 0. */
  node_t* cur = make_tree(1);
  print_bst(cur);
  printf("\n");
  assert(find_val(1, cur) == TRUE);

  /* Insert 1. */
  cur = insert(0, cur);
  assert(find_val(0, cur) == TRUE);
  print_bst(cur);
  printf("\n");

  /* Insert 2. */
  cur = insert(2, cur);
  assert(find_val(2, cur) == TRUE);

  /* Print the tree. */
  print_bst(cur);
  printf("\n");

  /* Insert 4. */
  cur = insert(4, cur);
  assert(find_val(4, cur) == TRUE);

  /* Insert 3 */
  cur = insert(3, cur);
  assert(find_val(3, cur) == TRUE);
  print_bst(cur);
  printf("\n");

  /* ADD YOUR TESTS HERE. */
  
  /* Delete the list. */
  delete_bst(cur);

  return 0;
}
