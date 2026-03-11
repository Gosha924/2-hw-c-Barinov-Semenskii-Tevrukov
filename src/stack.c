#include "stack.h"
#include "bst.h"
#include <stdlib.h>

stack* stackCreate()
{
    stack* Top = malloc(sizeof(stack));
    Top->next = NULL;
    Top->node = NULL;
    return Top;
}

void stackPush(stack* Top, Node* node)
{
    stack* newElem = malloc(sizeof(stack));
    newElem->node = node;
    newElem->next = Top->next;
    Top->next = newElem;
}

void stackPop(stack* Top)
{
    stack* elem = Top->next;
    if (elem != NULL) {
        Top->next = elem->next;
        free(elem);
    }
}

Node* stackTop(stack* Top)
{
    if (Top->next != NULL)
        return Top->next->node;
    return NULL;
}

void stackFree(stack* Top)
{
    while (Top->next != NULL) {
        stack* elem = Top->next;
        Top->next = elem->next;
        free(elem);
    }
    free(Top);
}
