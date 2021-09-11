#include "PListLib.c"

float getAVG(List L)
{
    int sum = 0;
    int n = 0;
    Position p = L;
    while (p->Next != NULL)
    {
        sum += retrieve(p, L);
        n++;
        p = Next(p);
    }
    return (float)sum / n;
}
int main()
{
    List L;
    readList(&L);
    printList(L);
    printf("%.3f", getAVG(L));
}