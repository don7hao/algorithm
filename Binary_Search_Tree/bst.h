#include <stdio.h>

typedef struct BinarySearchTree* BST;

struct BinarySearchTree{
    BST left;
    BST right;
    int key;
};


BST bst_find(int key, BST root);
BST find_max(BST root);
BST find_min(BST root);
BST bst_delete(int key, BST root);
BST bst_insert(int key, BST root);

