typedef enum {FALSE=0, TRUE=1} bool;

/*
 * Define a node structure.
 */
typedef struct node {
  int val;
  struct node* left;
  struct node* right;
} node_t;

/*
 * Creates a new node from a given value, allocating heap memory for it.
 */
node_t* make_tree(int val);

/*
 * Inserts a new value into a given binary search tree, allocating heap memory
 * for it.
 */
node_t* insert(int val, node_t* cur_root);

bool find_val(int val, node_t* root);

/*
 * Given a pointer to the root, frees the memory associated with an entire list.
 */
void delete_bst(node_t* root);

/* Given a pointer to the root, prints all of the values in a tree. */
void print_bst(node_t* root);
