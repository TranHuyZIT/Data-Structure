#include "PListLib.c"
int main()
{
    List L1 = readSet();
    List L2 = readSet();
    printList(L1);
    printList(L2);
    printList(unionSet(L1, L2));
}