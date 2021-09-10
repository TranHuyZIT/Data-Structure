#include "PListLib.c"
int main()
{
    List L;
    readList(&L);
    printList(L);
    printf("\n");
    ElementType x;
    scanf("%d", &x);
    removeAll(x, &L);
    printList(L);
}