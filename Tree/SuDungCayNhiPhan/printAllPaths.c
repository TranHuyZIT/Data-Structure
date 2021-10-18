#include "BinaryTree.c"

void printAllPaths(Tree T, int path[], int len, int pathlen)
{
    if (len == pathlen)
    {
        if (isLeaf(T))
        {
            path[len] = T->Data;
            printArray(path, pathlen + 1);
        }
    }
    else
    {
        if (T != NULL)
        {
            path[len] = T->Data;
            printAllPaths(T->Left, path, len + 1, pathlen);
            printAllPaths(T->Right, path, len + 1, pathlen);
        }
    }
}