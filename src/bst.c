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
    if (tree == NULL) {
        return;
    }
    freeNode(tree->root);
    free(tree);
}
