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

// task Bф

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

// task C

int nodeHeight(Node* node)
{
    if (node == NULL) {
        return 0;
    }

    int leftHeight = nodeHeight(node->left);
    int rightHeight = nodeHeight(node->right);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    }
    return rightHeight + 1;
}

int bstHeight(BST* tree)
{ // всп функция
    if (tree == NULL || tree->root == NULL) {
        return 0;
    }
    return nodeHeight(tree->root);
}

int nodeSize(Node* node)
{
    if (node == NULL) {
        return 0;
    }

    return 1 + nodeSize(node->right) + nodeSize(node->left);
}

int bstSize(BST* tree)
{
    if (tree == NULL || tree->root == NULL) {
        return 0;
    }
    return nodeSize(tree->root);
}

int bstMin(BST* tree)
{
    if (tree == NULL || tree->root == NULL) {
        return -1;
    }

    Node* current = tree->root;

    while (current->left != NULL) {
        current = current->left;
    }
    return current->key;
}

int bstMax(BST* tree)
{
    if (tree == NULL || tree->root == NULL) {
        return -1;
    }

    Node* current = tree->root;

    while (current->right != NULL) {
        current = current->right;
    }
    return current->key;
}

int nodeKthMin(Node* node, int* k)
{
    if (node != NULL) {
        int key = nodeKthMin(node->left, k);
        if (*k == 0) {
            return key;
        }
        *k -= 1;
        if (*k == 0) {
            return node->key;
        }
        return nodeKthMin(node->right, k);
    }
    return 0;
}

int bstKthMin(BST* tree, int k)
{
    if (k > bstSize(tree) || k <= 0) {
        printf("Value error\n");
        abort();
    }
    return nodeKthMin(tree->root, &k);
}
