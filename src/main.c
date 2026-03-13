#include "bst.h"
#include <stdio.h>

int main()
{
    BST* tree = createBST();

    bool isValud = bstIsValid(tree);
    printf("%d\n", isValud);
    bstFree(tree);
    BST* tree1 = createBST();
    bstInsert(tree1, 5);
    bstInsert(tree1, 3);
    bstInsert(tree1, 7);

    BST* tree2 = createBST();
    bstInsert(tree2, 4);
    bstInsert(tree2, 6);
    bstInsert(tree2, 2);

    BST* newBST = bstMerge(tree1, tree2);

    printf("\n");
    bstInorder(tree1);
    bstPostorder(tree1);
    bstPreorder(tree1);
    printf("\n");
    bstInorder(tree2);
    bstPostorder(tree2);
    bstPreorder(tree2);
    printf("\n");
    bstInorder(newBST);
    bstPostorder(newBST);
    bstPreorder(newBST);

    bstFree(tree1);
    bstFree(tree2);
    bstFree(newBST);

    return 0;
}
