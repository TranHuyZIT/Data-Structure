#include "BinaryTree.c"

int getHeight(Tree T)
{
    if (T == NULL)
        return 0;
    return 1 + max(getHeight(T->Left), getHeight(T->Right));
}

void getDiameter(Tree T, int *m)
{
    if (T != NULL)
    {
        getDiameter(T->Left, m);
        getDiameter(T->Right, m);
        if (*m < 1 + getHeight(T->Left) + getHeight(T->Right))
        {
            *m = 1 + getHeight(T->Left) + getHeight(T->Right);
        }
        // printf("%d %d\n", getHeight(T->Left), getHeight(T->Right));
    }
}