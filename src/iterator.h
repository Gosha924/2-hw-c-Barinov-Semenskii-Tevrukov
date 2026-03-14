#pragma once
#include "bst.h"
#include "stack.h"

typedef struct Iterator {
    stack* Top;
} Iterator;

Iterator* iteratorInit(BST* tree);
bool iteratorHasNext(Iterator* it);
/**
 * Возвращает следующий элемент при обходе дерева
 * @param it итератор
 * @return значение очередного узла
 * Если вызвать эту функцию, когда элементов больше нет,
 * программа вылетит с ошибкой "iteratorNext: no more elements".
 */
int iteratorNext(Iterator* it);
void iteratorFree(Iterator* it);
