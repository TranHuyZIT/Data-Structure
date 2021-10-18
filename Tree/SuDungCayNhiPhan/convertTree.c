#include "BinaryTree.c"

void Swap(Tree *a, Tree *b)
{
    Tree temp = *a;
    *a = *b;
    *b = temp;
}

void convertTreeUtilities(Tree T)
{
    if (T != NULL)
    {
        Swap(&T->Left, &T->Right);
        convertTreeUtilities(T->Left);
        convertTreeUtilities(T->Right);
    }
}
Tree convertTree(Tree T)
{
    convertTreeUtilities(T);
    return T;
}