#include "BinaryTree.c"

Tree createTree(char pre[], char in[], int startIn, int endIn)
{
    static int currentPre = 0;
    if (startIn > endIn)
        return NULL;

    Tree N = (Tree)malloc(sizeof(struct Node));
    N->Data = pre[currentPre++];
    if (startIn == endIn)
    {
        N->Left = NULL;
        N->Right = NULL;
    }
    else
    {
        int inOrderIndex = findIndex(N->Data, in, startIn, endIn);
        N->Left = createTree(pre, in, startIn, inOrderIndex - 1);
        N->Right = createTree(pre, in, inOrderIndex + 1, endIn);
    }
    return N;
}