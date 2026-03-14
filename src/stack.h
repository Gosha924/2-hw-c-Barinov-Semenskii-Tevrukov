#pragma once
#include "bst.h"

typedef struct stack {
    Node* node;
    struct stack* next;
} stack;

stack* stackCreate();
void stackPush(stack* Top, Node* node);
void stackPop(stack* Top);
Node* stackTop(stack* Top);
void stackFree(stack* Top);
