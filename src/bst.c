#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

// task A

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
    if (tree == NULL) {
        return 0;
    }
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

// task B

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
    printf("\n");
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

void bstDelete(BST* tree, int value)
{
    if (tree == NULL || tree->root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    Node* current = tree->root;
    Node* pref = NULL;
    bool flag = false;

    while (current != NULL) {
        if (value < current->key) {
            pref = current;
            current = current->left;
        } else if (value > current->key) {
            pref = current;
            current = current->right;
        } else {
            flag = true;
            break;
        }
    }

    if (!flag) {
        printf("Value not found\n");
        return;
    }

    if (current->left == NULL && current->right == NULL) {
        if (pref == NULL) {
            tree->root = NULL;
        } else if (pref->left == current) {
            pref->left = NULL;
        } else {
            pref->right = NULL;
        }
        free(current);
        tree->size--;
    } else if (current->left == NULL || current->right == NULL) {
        Node* child;
        if (current->left != NULL) {
            child = current->left;
        } else {
            child = current->right;
        }

        if (pref == NULL) {
            tree->root = child;
        } else if (pref->left == current) {
            pref->left = child;
        } else {
            pref->right = child;
        }
        free(current);
        tree->size--;
    } else {
        Node* pref_search = NULL;
        Node* current_search = current->right;

        while (current_search->left != NULL) {
            pref_search = current_search;
            current_search = current_search->left;
        }

        current->key = current_search->key;

        if (pref_search == NULL) {
            current->right = current_search->right;
        } else {
            pref_search->left = current_search->right;
        }
        free(current_search);
        tree->size--;
    }
}

int main()
{
    return 0;
}