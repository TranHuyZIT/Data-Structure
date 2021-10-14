#include "BinaryTree.c"

int max(int a, int b, int c)
{
    int tmp = a > b ? a : b;
    return tmp > c ? tmp : c;
}
int findMax(Tree T)
{
    if (T == NULL)
        return 0;
    else
    {
        return max(findMax(T->Left), findMax(T->Right), T->Data);
    }
}
