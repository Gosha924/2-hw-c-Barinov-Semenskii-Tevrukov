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
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}
void inorderRecursive(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderRecursive(root->left);
    printf("%d ", root->key);
    inorderRecursive(root->right);
}

void bstInorder(BST* tree) {
    if (tree == NULL || tree->root == NULL) {
        printf("Дерево пусто\n");
        return;
    }

    printf("Inorder обход: ");
    inorderRecursive(tree->root);
    printf("\n");
}

int main() {
    BST* tree = createBST();
    
    return 0;
}
