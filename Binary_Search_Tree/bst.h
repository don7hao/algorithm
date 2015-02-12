#include <stdio.h>

typedef struct BinarySearchTree* BST;

struct BinarySearchTree{
    BST left;
    BST right;
    int key;
};


BST bst_find(BST root, int key);

