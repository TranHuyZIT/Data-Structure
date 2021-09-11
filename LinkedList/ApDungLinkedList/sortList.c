#include "PListLib.c"
int main()
{
    List L;
    readList(&L);
    printList(L);
    sortList(&L);
    printList(L);
}