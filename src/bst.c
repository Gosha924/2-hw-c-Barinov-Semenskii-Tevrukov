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

BST* bstCreate(void)
{
    BST* tree = malloc(sizeof(BST));
    tree->root = NULL;
    tree->size = 0;
    return tree;
}

void bstInsert(BST* tree, int value)
{
    Node* node = malloc(sizeof(Node));
    node->key = value;
    node->left = NULL;
    node->right = NULL;

    if (tree->size == 0) {
        tree->root = node;
        tree->size = 1;
        return;
    }
    Node* current = tree->root;
    while (1) {
        if (value > current->key) {
            if (current->right == NULL) {
                current->right = node;
                tree->size++;
                return;

            } else {
                current = current->right;
            }
        } else if (value < current->key) {
            if (current->left == NULL) {
                current->left = node;
                tree->size++;
                return;

            } else {
                current = current->left;
            }
        } else {
            free(node);
            return;
        }
    }
}
bool bstContains(BST* tree, int value)
{
    if (tree->root == NULL) {
        return 0;
    }
    Node* node = tree->root;
    while (node != NULL) {
        if (node->key == value) {
            return 1;
        } else if (node->key < value) {
            node = node->right;
        } else if (node->key > value) {
            node = node->left;
        }
    }
    return 0;
}

void freeNode(Node* node)
{
    if (node == NULL) {
        return;
    }
    freeNode(node->left);
    freeNode(node->right);
    free(node);
}

void bstFree(BST* tree)
{
}

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
    if (tree == NULL) {
        printf("Tree is empty\n");
        return;
    }
    if (tree->root == NULL) {
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
    if (tree == NULL) {
        printf("Tree is empty\n");
        return;
    }
    if (tree->root == NULL) {
        printf("Tree is empty\n");
        return;
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
    if (tree == NULL) {
        printf("Tree is empty\n");
        return;
    }
    if (tree->root == NULL) {
        printf("Tree is empty\n");
        return;
    }
    printf("Postorder\n");
    postorderRecursive(tree->root);
}

int main()
{
    return 0;
}
