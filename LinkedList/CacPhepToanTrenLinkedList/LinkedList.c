#include "define.h"

// Function Prototypes
Position createNode(ElementType x);                   // Create a Node.
void makenullList(List *pL);                          // Create an empty List.
void readList(List *pL);                              // Read List from user input.
List readSet();                                       // Read a set from user input
List intersection(List L1, List L2);                  // Find the intersection between two list.
void normalize(List *pL);                             // Normalize a list.
int emptyList(List L);                                // Check if list is empty or not.
ElementType retrieve(Position p, List L);             // Retrieve an element from a specfic position.
void insertList(ElementType x, Position P, List *pL); // Insert a new Node next to P Node.
void deleteList(Position P, List *pL);                //Delete a Node next to P if any.
Position first(List L);                               // Return first Position in List.
Position endList(List L);                             //Return last Position of List
Position Next(Position P);                            // Return next position of P;
Position Previous(Position P, List L);                // Return previous position of P;
Position locate(ElementType x, List L);               // Locate the Position of ElementType x;
void printList(List L);                               // Print The List on the screen.
int member(ElementType x, List L);                    // Check if and element exist in the list.
void append(ElementType x, List *pL);                 // Append a Node to the end of list;
void addFirst(ElementType x, List *pL);               // Add a Node at the starting Position.
//

// Functions
Position createNode(ElementType x)
{
    Position p = (Position)malloc(sizeof(struct Node));
    p->Next = NULL;
    p->Element = x;
    return p;
}

void makenullList(List *pL)
{
    (*pL) = (Position)malloc(sizeof(struct Node));
    (*pL)->Next = NULL;
}

void readList(List *pL)
{
    makenullList(pL); // Create An Empty List
    int n, i;
    Position P = *pL;
    Position N;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        // For Every Loop, create a new node and added into List
        ElementType tmp;
        scanf("%d", &tmp);
        append(tmp, pL);
    }
}

List readSet()
{
    List L;
    makenullList(&L);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        ElementType tmp;
        scanf("%d", &tmp);
        if (!member(tmp, L))
        {
            addFirst(tmp, &L);
        }
    }
    return L;
}

int emptyList(List L)
{
    return L->Next == NULL; // Check if headerNode->Next is Null.
}

ElementType retrieve(Position p, List L)
{
    if (p->Next != NULL)
    {
        return p->Next->Element;
    }
}

void insertList(ElementType x, Position P, List *pL)
{
    Position N = createNode(x);
    N->Next = P->Next;
    P->Next = N;
}

void deleteList(Position P, List *pL)
{
    if (P->Next != NULL)
    {
        Position tmp = P->Next;
        P->Next = tmp->Next;
        free(tmp);
    }
}

Position first(List L)
{
    return L;
}

Position Next(Position P)
{
    return P->Next;
}

Position Previous(Position P, List L)
{
    Position Q = L;
    while (Q->Next != P)
    {
        Q = Next(Q);
    }
    return Q;
}

Position endList(List L)
{
    Position P = first(L);
    while (P->Next != NULL)
    {
        P = Next(P);
    }
    return P;
}

Position locate(ElementType x, List L)
{
    Position P = first(L);
    Position E = endList(L);
    while (P != E)
    {
        if (retrieve(P, L) == x)
        {
            return P; // Found x then return P position
        }
        P = Next(P);
    }
    return P; // Return Endlist
}

void printList(List L)
{
    Position P = L;
    while (P->Next != NULL) // Loop while not reaching the last Node.
    {
        printf("%d ", retrieve(P, L));
        P = Next(P);
    }
}

int member(ElementType x, List L)
{
    Position P = L;
    Position E = endList(L);
    while (P != E)
    {
        if (retrieve(P, L) == x)
        {
            return 1;
        }
        P = Next(P);
    }
    return 0;
}

void append(ElementType x, List *pL)
{
    insertList(x, endList(*pL), pL);
}

void addFirst(ElementType x, List *pL)
{
    insertList(x, first(*pL), pL);
}
List intersection(List L1, List L2)
{
    List L;
    makenullList(&L);
    Position p = first(L1);
    while (p->Next != NULL)
    {
        ElementType tmp = retrieve(p, L1);
        if (member(tmp, L2))
        {
            append(tmp, &L);
        }
        p = Next(p);
    }
    normalize(&L);
    return L;
}
void normalize(List *pL)
{
    Position p = first(*pL);
    Position q;
    while (p->Next != NULL)
    {
        q = Next(p);
        while (q->Next != NULL)
        {
            if (q->Next->Element == p->Next->Element)
            {
                deleteList(q, pL);
            }
            else
                q = Next(q);
        }
        p = Next(p);
    }
}
void removeAll(ElementType x, List *pL)
{
    Position tmp = locate(x, *pL);
    while (tmp != endList(*pL))
    {
        deleteList(tmp, pL);
        tmp = locate(x, *pL);
    }
}
//