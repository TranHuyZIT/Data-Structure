#include <stdio.h>
#include <stdlib.h>

// Definitions
typedef int ElementType; // define ElementType inside a Node.
struct Node
{
    ElementType Element; // Store Element
    struct Node *Pre;    // Pointer to previous node.
    struct Node *Next;   // Pointer to next node.
};

typedef struct Node *Position;
struct list // Define a List
{
    //List will store 2 position Head and Tail for better access and control.
    Position Head;
    Position Tail;
    // Head is an empty Position, while Tail store data.
};
typedef struct list List;
typedef List *pList; // pList: Pointer to struct List

// *******

// Prototypes
Position createNode(ElementType data);
pList createList();
void addHead(pList l, int data);
void addTail(pList l, int data);
void addAt(pList l, int k, int x);
void delHead(pList l);
void delTail(pList l);
void delAt(pList l, int k);
Position Next(Position P);
Position Previous(Position P);
void printList(List L);
pList readList();
ElementType retrieve(Position p);
Position locate(ElementType x, List L);
// *******

// Functions
Position createNode(ElementType data)
{
    Position p = (Position)malloc(sizeof(struct Node));
    p->Element = data;
    p->Next = NULL;
    p->Pre = NULL;
    return p;
}
pList createList()
{
    // Allocate new struct List and assign to pointer L.
    pList L = (pList)malloc(sizeof(List));
    L->Head = (Position)malloc(sizeof(struct Node));
    L->Head->Next = NULL;
    L->Head->Pre = NULL;
    L->Tail = L->Head;
    return L;
}
void addHead(pList l, int data)
{
    Position tmp = createNode(data);
    tmp->Next = l->Head->Next;
    l->Head->Pre = tmp;
    l->Head->Next = tmp;
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
        for (i = 0; i < k; i++)
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
    Position p = l->Head->Next->Next;
    Position tmp = l->Head->Next;
    p->Pre = l->Head;
    l->Head->Next = p;
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
    for (i = 0; i < k; i++)
    {
        p = p->Next;
    }
    Position tmp = p->Next;
    Position p2 = tmp->Next;
    p->Next = p2;
    p2->Pre = p;
    free(tmp);
}
Position Next(Position P)
{
    return P->Next;
}
Position Previous(Position P)
{
    return P->Pre;
}
void printList(List L)
{
    Position p = L.Head;
    while (p->Next != NULL)
    {
        printf("%d ", p->Next->Element);
        p = Next(p);
    }
    printf("\n");
}
pList readList()
{
    pList L = createList();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        ElementType data;
        scanf("%d", &data);
        addTail(L, data);
    }
    return L;
}
ElementType retrieve(Position p)
{
    if (p->Next != NULL)
    {
        return p->Next->Element;
    }
    return INT_MAX;
}
Position locate(ElementType x, List L)
{
    Position P = L.Head;
    while (P->Next != NULL)
    {
        if (P->Next->Element == x)
        {
            return P;
        }
        P = Next(P);
    }
    return P;
}

// ******