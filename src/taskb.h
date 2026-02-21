#pragma once

typedef struct node {
    int key;
    struct node* left;
    struct node* right;
} Node;

typedef struct bst {
    Node* root;
    int size;
} BST;

BST* createBST(void);
Node* createNode(int key);
void bstInorder(BST* tree);
void inorderRecursive(Node* root);