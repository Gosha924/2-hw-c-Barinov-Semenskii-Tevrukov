#include "bst.h"
#include <stdio.h>

int main()
{
    BST* tree = createBST();

    bool isValud = bstIsValid(tree);
    printf("%d\n", isValud);
    bstFree(tree);

    return 0;
}