#pragma once
#include <stdbool.h>

//задача A
void bstInsert(BST* tree, int value);
bool bstContains(BST* tree, int value);
void bstFree(BST* tree);

//задача B
void bstInorder(BST* tree);
void bstPreorder(BST* tree);
void bstPostorder(BST* tree);

//задача С
int bstHeight(BST* tree);
int bstSize(BST* tree);
int bstMin(BST* tree);
int bstMax(BST* tree);

//.....