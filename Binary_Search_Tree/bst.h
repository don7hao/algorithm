#include <stdio.h>

typedef struct Binary_Search_Tree* BST;

struct binary_search_tree{
    BST left;
    BST right;
    int key;
};


BST bst_find(BST root, int key);

