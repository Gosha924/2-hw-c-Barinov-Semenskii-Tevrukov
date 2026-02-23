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
void preorderRecursive(Node* root);
void bstPreorder(BST* tree);
void postorderRecursive(Node* root);
void bstPostorder(BST* tree);