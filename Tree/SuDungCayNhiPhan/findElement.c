#include "BinaryTree.c"

Tree findElement(int x, Tree T)
{
    if (T == NULL)
        return NULL;
    else
    {
        if (T->Data == x)
            return T;
        if (findElement(x, T->Left) != NULL)
        {
            return findElement(x, T->Left);
        }
        else
        {
            return findElement(x, T->Right);
        }
    }
}