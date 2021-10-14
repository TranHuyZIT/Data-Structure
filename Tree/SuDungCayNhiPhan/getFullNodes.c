#include "BinaryTree.c"

int isFullNodes(Tree T)
{
    if (T == NULL)
        return 0;
    else
        return (T->Left != NULL) && (T->Right != NULL);
}
int getFullNodes(Tree T)
{
    if (T == NULL)
        return 0;
    else if (isFullNodes(T))
        return 1 + getFullNodes(T->Left) + getFullNodes(T->Right);
    else
    {
        return getFullNodes(T->Left) + getFullNodes(T->Right);
    }
}
