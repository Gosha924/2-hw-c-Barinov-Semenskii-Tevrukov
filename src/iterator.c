#include "iterator.h"
#include "bst.h"
#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

Iterator* iteratorInit(BST* tree)
{
    if (tree == NULL || tree->root == NULL) {
        return NULL;
    }
    Iterator* it = malloc(sizeof(Iterator));
    it->Top = stackCreate();
    Node* node = tree->root;
    while (node != NULL) {
        stackPush(it->Top, node);
        node = node->left;
    }
    return it;
}

bool iteratorHasNext(Iterator* it)
{
    return it != NULL && it->Top != NULL && it->Top->next != NULL;
}

int iteratorNext(Iterator* it)
{
    if (iteratorHasNext(it) == 0) {
        printf("iteratorNext: no more elements\n");
        abort();
    }
    Node* node = stackTop(it->Top);
    stackPop(it->Top);
    if (node->right != NULL) {
        Node* elem = node->right;
        while (elem != NULL) {
            stackPush(it->Top, elem);
            elem = elem->left;
        }
    }
    return node->key;
}

void iteratorFree(Iterator* it)
{
    stackFree(it->Top);
    free(it);
}
