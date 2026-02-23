#include "taskb.h"
#include <stdio.h>
#include <stdlib.h>

BST* createBST()
{
    BST* tree = (BST*)malloc(sizeof(BST));
    if (tree) {
        tree->root = NULL;
        tree->size = 0;
    }
    return tree;
}
Node* createNode(int key)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}
void inorderRecursive(Node* root)
{
    if (root == NULL) {
        return;
    }
    inorderRecursive(root->left);
    printf("%d ", root->key);
    inorderRecursive(root->right);
}

void bstInorder(BST* tree)
{
    if (tree == NULL || tree->root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    printf("Inorder \n");
    inorderRecursive(tree->root);
    printf("\n");
}

void preorderRecursive(Node* root)
{
    if (root == NULL) {
        return;
    }
    printf("%d ", root->key);
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

void bstPreorder(BST* tree)
{
    if (tree == NULL || tree->root == NULL) {
        printf("Tree is empty\n");
    }
    printf("Preorder\n");
    preorderRecursive(tree->root);
    printf("/n");
}

void postorderRecursive(Node* root)
{
    if (root == NULL) {
        return;
    }
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    printf("%d ", root->key);
}

void bstPostorder(BST* tree)
{
    if (tree == NULL || tree->root == NULL) {
        printf("Tree is empty\n");
    }
    printf("Postorder\n");
    postorderRecursive(tree->root);
}

int main()
{
    return 0;
}
