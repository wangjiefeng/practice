typedef enum {FALSE=0, TRUE=1} bool;

/*
 * Define a tree structure.
 */
typedef struct bst {
  int* vals;
  int size;
} bst_t;

/* Returns a bst_t structure with an int array vals of size "size" and the
 * size field set appropriately. */
bst_t* make_tree(int size);

/*
 * Initialize the binary search tree.
 * HINT: What should we initialize values to?  What requirements might we have
 * to add to the tree specification?
 */
void init_tree(bst_t* tree);

/*
 * Inserts a new value into a given tree.
 */
void insert(int val, bst_t* tree);

bool find_val(int val, bst_t* tree);

/*
 * Given a pointer to the root, frees the memory associated with an entire list.
 */
void delete_bst(bst_t* tree);

/* Given a pointer to the root, prints all of the values in a list. */
void print_bst(bst_t* tree);
