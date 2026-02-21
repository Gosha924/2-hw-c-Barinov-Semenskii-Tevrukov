#include "bst.h"
#include <stdio.h>

int main()
{
    BST* tree = bstCreate();

    bstInsert(tree, 5);
    bstInsert(tree, 3);
    bstInsert(tree, 7);

    printf("%d ", bstContains(tree, 5));
    printf("%d ", bstContains(tree, 3));
    printf("%d ", bstContains(tree, 7));
    printf("%d\n", bstContains(tree, 9));

    bstFree(tree);

    return 0;
}