#include "bst.h"
#include <string.h>
#include <stdlib.h>

BST bst_delete(int key, BST root)
{
    //分三种情况
    //1. 删除节点是叶子节点：
    //  a.直接删除节点
    //2. 删除节点只有一个左儿子或右儿子：
    //  a.用儿子节点替代删除节点
    //3. 删除节点有左右儿子(两种方法)：
    //  a.取右子树的最小元素替代删除节点
    //  b.取左子树的最大元素替代删除节点

    if (NULL == root)
        return NULL;

    BST node = root, *prev = &root;
    do{
        if (key < node->key){
            prev = &node->left;
            node = node->left;
        }else if (key > node->key){
            prev = &node->right;
            node = node->right;
        }else{
            break;
        }
    }while(node != NULL);

    //没有找到
    if (NULL == node)
        return NULL;

    if (NULL != node->right && NULL != node->left){
        //采用在右子树中找最小元素
        BST tmp = node->right, *tmpprev = &node->right;
        while (NULL != tmp->left){
            tmpprev = &tmp->left;
            tmp = tmp->left;
        }
        *tmpprev = tmp->right;
        tmp->right = node->right;
        tmp->left  = node->left;
        if (*prev == root)
        {
            //删除节点为root节点
            root = tmp;
        }else
            *prev = tmp;
    }else if (NULL == node->right){
        *prev = node->left;
    }else if (NULL == node->left){
        *prev = node->right;
    }

    free(node);
    node = NULL;
    return root;
}

BST bst_insert(int key, BST root)
{
    BST node = root;
    if (!node){
        node = (BST)calloc(1, sizeof(struct BinarySearchTree));
        node->key = key;
        node->right = NULL;
        node->left  = NULL;
    }else{
        if (key < node->key){
            node->left = bst_insert(key, node->left);
        }else if (key > node->key){
            node->right = bst_insert(key, node->right);
        }else{
            //该节点已经存在return
        }
    }

    return node;
}

BST bst_find(int key, BST root)
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

void bst_print(BST root)
{
    if (NULL == root)
        return;
    bst_print(root->left);
    bst_print(root->right);
    printf("%d\n", root->key);

    return;
}

int main(void)
{
    int array[] = {9 , 8, 10 , 3, 2, 5};

    int idx = 0x00;
    BST root = bst_insert(7, NULL);
    for (; idx < sizeof(array)/sizeof(int); idx++)
        bst_insert(array[idx], root);

    printf("bst:\n");
    bst_print(root);

    printf("input a number that you want to delete:\n");
    int num = 0x00;
    scanf("%d", &num);
    root = bst_delete(num, root);


    printf("\nbst:\n");
    bst_print(root);

    return 0x00;

}
