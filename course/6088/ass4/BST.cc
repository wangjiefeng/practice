#include "BST.h"
#include <iostream>
#include <assert.h>
using namespace std;
//constructor
BST::BST()
{
	size = 100;
	vals = new int[100]();
	for(int i = 0; i < size; i++) {
		vals[i] = 1024;
	}
}

// destructor
BST::~BST()
{
	delete[] vals;
}

// inserts "val" into the tree
void BST::insert(int val)
{
	assert(vals != NULL);
	int i = 0;
	while(i < size && vals[i] != 1024) {
		if(val < vals[i])
			i = 2 * i + 1;
		else
			i = 2 * i + 2;
	}
	vals[i] = val;
}

// returns true if and only if "val" exists in the tree.
bool BST::find(int val)
{
	assert(vals != NULL);
	int i = 0;
	while(i < size && vals[i] != 1024) {
		if(vals[i] == val)
			return true;
		if(val < vals[i])
			i = 2 * i + 1;
		else
			i = 2 * i + 2;
	}
	return false;
}

// prints the tree elements in the in-order traversal order
void BST::print_inorder()
{
	assert(vals != NULL);
	int i = 0;
	while(i < size) {
		if(vals[i] == 1024) {
			i++;
			continue;
		}
		cout << vals[i++] << " ";
	}
}
