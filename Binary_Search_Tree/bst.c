#include "bst.h"
#include <string.h>
#include <stdlib.h>

BST bst_delet(int key, BST root)
{
    //分三种情况
    //1. 删除节点是叶子节点：
    //  a.直接删除节点
    //2. 删除节点只有一个左儿子或右儿子：
    //  a.用儿子节点替代删除节点
    //3. 删除节点有左右儿子(两种方法)：
    //  a.取右子树的最小元素替代删除节点
    //  b.取左子树的最大元素替代删除节点
}

BST bst_insert(int key, BST root)
{
    BST node = root;
    if (!root){
        root = (BST)calloc(1, sizeof(struct BinarySearchTree));
        root->key = key;
        root->right = NULL;
        root->left  = NULL;
    }else{
        if (key < node->key){
            node->right = bst_insert(key, node->right);
        }else if (key > node->key){
            node->left = bst_insert(key, node->left);
        }else{
            //该节点已经存在return
        }
    }

    return node;
}

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
