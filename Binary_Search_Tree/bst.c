#include "bst.h"

BST bst_find(BST root, int key)
{
    BST node = root;
    while (NULL != node){
        if (key < node->key)
            node = node->left;
        else if (key > node->key)
            node = node->right;
        else
            return node;
    }

    return NULL;
}

BST find_max(BST root)
{
    BST node = root;
    if (NULL != node){
        while (NULL != node->right){
            node = node->right;
        }
    }

    return node;
}

BST find_min(BST root)
{
    BST node = root;
    if (NULL != node){
        while (NULL != node->left){
            node = node->left;
        }
    }

    return node;
}

BST create_bst(BST root)
{

}

int main(void)
{

}
