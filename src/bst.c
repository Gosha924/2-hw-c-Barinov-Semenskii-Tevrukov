#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node* left;
    struct node* right;
} Node;

typedef struct bst {
    Node* root;
    int size;
} BST;

void bstInsert(BST* tree, int value)
{
}

bool bstContains(BST* tree, int value)
{
    return false;
}

void bstFree(BST* tree)
{
}
