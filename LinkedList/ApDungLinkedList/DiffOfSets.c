#include "PListLib.c"
int main()
{
    List L1, L2, L;
    L1 = readSet();
    L2 = readSet();
    printList(L1);
    printList(L2);
    L = diffOfSets(L1, L2);
    printList(L);
}