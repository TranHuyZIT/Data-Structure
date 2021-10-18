#include "BinaryTree.c"

int isMirrors(Tree T1, Tree T2)
{
    if (T1 == NULL && T2 == NULL)
        return 1;
    else
    {
        if (T1 != NULL && T2 != NULL)
        {
            if (T1->Data == T2->Data)
            {
                return isMirrors(T1->Left, T2->Right) &&
                       isMirrors(T1->Right, T2->Left);
            }
        }
        return 0;
    }
}