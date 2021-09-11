#include "PListLib.c"
int main()
{
    List L1 = readSet();
    List L2 = readSet();
    printList(L1);
    printList(L2);
    List sum = sumSet(L1, L2);
    printList(sum);
    return 0;
}