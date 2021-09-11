#include "PListLib.c"

List copyEvenNum(List L)
{
    List res;
    makenullList(&res);
    Position p = first(L);
    while (p->Next != NULL)
    {
        ElementType tmp = retrieve(p, L);
        if (tmp % 2 == 0)
        {
            append(tmp, &res);
        }
        p = Next(p);
    }
    return res;
}
int main()
{
    List L;
    readList(&L);
    printList(L);
    List Even = copyEvenNum(L);
    List Odd = diffOfSets(L, Even);
    printList(Odd);
    printList(Even);
    return 0;
}