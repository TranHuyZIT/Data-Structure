#include <stdio.h>
#include <stdlib.h>

// Definitions
typedef struct
{
    double he_so;
    int bac;
} DonThuc;

struct Node
{
    DonThuc e;
    struct Node *Next;
};
typedef struct Node *Position;
typedef Position DaThuc;

// Prototypes:
DaThuc khoitao();
void chenDonThuc(DonThuc s, DaThuc *pL);
DaThuc congDaThuc(DaThuc D1, DaThuc D2);
void inDaThuc(DaThuc d);

// Functions
DaThuc khoitao()
{
    Position N = (Position)malloc(sizeof(struct Node));
    N->Next = NULL;
    return N;
}
void chenDonThuc(DonThuc s, DaThuc *pL)
{
    Position p = (*pL);
    DonThuc current;
    while (p->Next != NULL)
    {
        current = p->Next->e;
        if (current.bac < s.bac)
        {
            Position N = (Position)malloc(sizeof(struct Node));
            N->e = s;
            N->Next = p->Next;
            p->Next = N;
            return;
        }
        else if (current.bac == s.bac)
        {
            (p->Next->e).he_so += s.he_so;
            return;
        }
        p = p->Next;
    }
    Position N = (Position)malloc(sizeof(struct Node));
    N->e = s;
    N->Next = p->Next;
    p->Next = N;
}

DaThuc congDaThuc(DaThuc D1, DaThuc D2)
{
    DaThuc D3 = khoitao();
    Position p = D1;
    while (p->Next != NULL)
    {
        chenDonThuc(p->Next->e, &D3);
        p = p->Next;
    }
    Position q = D2;
    while (q->Next != NULL)
    {
        chenDonThuc(q->Next->e, &D3);
        q = q->Next;
    }
    return D3;
}
void inDaThuc(DaThuc d)
{
    Position p = d;
    while (p->Next != NULL)
    {
        DonThuc current = p->Next->e;
        printf("%.3lfX^%d", current.he_so, current.bac);
        if (p->Next->Next != NULL)
        {
            printf(" + ");
        }
        p = p->Next;
    }
}