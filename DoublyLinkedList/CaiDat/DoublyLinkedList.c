#include "define.h"
Position createNode(ElementType data)
{
    Position p = (Position)malloc(sizeof(struct Node));
    p->Element = data;
    p->Next = NULL;
    p->Pre = NULL;
    return p;
}
pList createList(int data)
{
    // Allocate new struct List and assign to pointer L.
    pList L = (pList)malloc(sizeof(struct List));
    L->Head = createNode(data);
    L->Tail = L->Head;
    return L;
}
void addHead(pList l, int data)
{
    Position tmp = createNode(data);
    tmp->Next = l->Head;
    l->Head->Pre = tmp;
    l->Head = tmp;
}
void addTail(pList l, int data)
{
    Position tmp = createNode(data);
    tmp->Next = NULL;
    l->Tail->Next = tmp;
    tmp->Pre = l->Tail;
    l->Tail = tmp;
}
void addAt(pList l, int k, int x)
{
    if (k == 0)
    {
        addHead(l, x);
    }
    else
    {
        Position p = l->Head;
        int i;
        for (i = 0; i < k - 1; i++)
        {
            p = p->Next;
        }
        Position tmp = createNode(x);
        tmp->Pre = p;
        tmp->Next = p->Next;
        p->Next->Pre = tmp;
        p->Next = tmp;
    }
}
void delHead(pList l)
{
    Position p = l->Head->Next;
    Position tmp = l->Head;
    p->Pre = NULL;
    l->Head = p;
    free(tmp);
}
void delTail(pList l)
{
    Position p = l->Tail->Pre;
    Position tmp = l->Tail;
    p->Next = NULL;
    free(tmp);
    l->Tail = p;
}
void delAt(pList l, int k)
{
    Position p = l->Head;
    int i;
    for (i = 0; i < k - 1; i++)
    {
        p = p->Next;
    }
    Position tmp = p->Next;
    Position p2 = tmp->Next;
    p->Next = p2;
    p2->Pre = p;
    free(tmp);
}

void printList(pList l)
{
    Position p = l->Head;
    while (p != NULL)
    {
        printf("%d ", p->Element);
        p = p->Next;
    }
}
int main()
{
    int x, n, k, i;
    scanf("%d%d", &n, &x);
    pList l = createList(x);
    for (i = 1; i < n; i++)
    {
        scanf("%d", &x);
        addTail(l, x);
    }
    scanf("%d", &k);
    if (k == 0)
    {
        delHead(l);
    }
    else if (k == n - 1)
    {
        delTail(l);
    }
    else
    {
        delAt(l, k);
    }
    printList(l);
}