#pragma once
#include "bst.h"
#include "stack.h"

typedef struct Iterator {
    stack* Top;
} Iterator;

Iterator* iteratorInit(BST* tree);
bool iteratorHasNext(Iterator* it);
int iteratorNext(Iterator* it);
void iteratorFree(Iterator* it);
