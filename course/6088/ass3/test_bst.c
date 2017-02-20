#include <assert.h>
#include <stdio.h>
#include "bst.h"

int main() {
  /* Insert 0. */
  bst_t* cur = make_tree(32);
  init_tree(cur);

  insert(1, cur);
  assert(find_val(1, cur) == TRUE);
  print_bst(cur); printf("\n");

  /* Insert 1. */
  insert(0, cur);
  assert(find_val(0, cur) == TRUE);
  print_bst(cur); printf("\n");

  /* Insert 2. */
  insert(2, cur);
  assert(find_val(2, cur) == TRUE);
  print_bst(cur); printf("\n");

  /* Insert 4. */
  insert(4, cur);
  assert(find_val(4, cur) == TRUE);
  print_bst(cur); printf("\n");

  /* Insert 3 */
  insert(3, cur);
  assert(find_val(3, cur) == TRUE);
  print_bst(cur);
  printf("\n");

  /* ADD YOUR TESTS HERE. */
  
  /* Delete the list. */
  delete_bst(cur);

  return 0;
}
