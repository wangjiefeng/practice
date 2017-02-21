#include <iostream>
#include "BST.h"

int main () {

  BST tree;

  // Test case 1: insert 1
  std::cout << "Test case 1: Insert 1";
  tree.insert(1);
  tree.print_inorder();
  if (tree.find(1)) 
    std::cout << "Passed!\n";
  else 
    std::cout << "Failed! Tree should contain 1.\n";

  // Test case 2: insert 7
  std::cout << "Test case 2: Insert 7\n";
  tree.insert(7);
  tree.print_inorder();
  if (tree.find(1) && tree.find(7)) 
    std::cout << "Passed!\n";
  else 
    std::cout << "Failed! Tree should contain 1, 7.\n";

  // Test case 3: insert -1
  std::cout << "Test case 3: Insert -1\n";
  tree.insert(-1);
  tree.print_inorder();
  if (tree.find(-1) && tree.find(7) && tree.find(1))
    std::cout << "Passed!\n";
  else     
    std::cout << "Failed! Tree should contain -1, 1, 7.\n";

  // ADD YOUR TESTS HERE
  
  return 0;
}
