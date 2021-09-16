#include <stdio.h>
#include <stdlib.h>
// Definitons
typedef int ElementType;
struct Node
{
    ElementType Element;
    struct Node *Next;
};
typedef struct Node *Position;
typedef Position List;

// ***** Function Prototypes

// LinkedList:
Position createNode(ElementType x);                   // Create a Node.
void makenullList(List *pL);                          // Create an empty List.
void readList(List *pL);                              // Read List from user input.
int emptyList(List L);                                // Check if list is empty or not.
ElementType retrieve(Position p, List L);             // Retrieve an element from a specfic position.
void insertList(ElementType x, Position P, List *pL); // Insert a new Node next to P Node.
void deleteList(Position P, List *pL);                //Delete a Node next to P if any.
Position first(List L);                               // Return first Position in List.
Position endList(List L);                             //Return last Position of List
Position Next(Position P);                            // Return next position of P;
Position Previous(Position P, List L);                // Return previous position of P;
Position locate(ElementType x, List L);               // Locate the Position of ElementType x;
void sortList(List *pL);                              // Sort the List
void printList(List L);                               // Print The List on the screen.
int member(ElementType x, List L);                    // Check if and element exist in the list.
void append(ElementType x, List *pL);                 // Append a Node to the end of list;
void addFirst(ElementType x, List *pL);               // Add a Node at the starting Position.

// Set
List diffOfSets(List L1, List L2);   // Return a List of differences between L1 and L2.
List sumSet(List L1, List L2);       // Return a list of sumset.
List unionSet(List L1, List L2);     // Return a list of union of the two set
List readSet();                      // Read a set from user input
List intersection(List L1, List L2); // Find the intersection between two list.
void normalize(List *pL);            // Normalize a list.
// *********

// ***** Functions:
// LinkedList
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
        N = createNode(tmp);
        P->Next = N;
        P = P->Next;
    }
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
    printf("\n");
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

void removeAll(ElementType x, List *pL)
{
    Position tmp = locate(x, *pL);
    Position end = endList(*pL);
    while (tmp != end)
    {
        deleteList(tmp, pL);
        tmp = locate(x, *pL);
    }
}

void sortList(List *pL)
{
    Position P = first(*pL);
    Position Q;
    while (P->Next != NULL)
    {
        Q = P->Next;
        while (Q->Next != NULL)
        {
            ElementType p = retrieve(P, *pL);
            ElementType q = retrieve(Q, *pL);
            if (q < p)
            {
                ElementType tmp = p;
                P->Next->Element = q;
                Q->Next->Element = tmp;
            }
            Q = Next(Q);
        }
        P = Next(P);
    }
}

// Set
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
List diffOfSets(List L1, List L2)
{
    List L;
    makenullList(&L);
    Position P = L1;
    while (P->Next != NULL)
    {
        if (!member(retrieve(P, L1), L) && !member(retrieve(P, L2), L2))
            append(P->Next->Element, &L);
        P = Next(P);
    }
    return L;
}
List unionSet(List L1, List L2)
{
    List L;
    makenullList(&L);
    Position P = L1;
    while (P->Next != NULL)
    {
        ElementType tmp = retrieve(P, L1);
        if (member(tmp, L2))
        {
            append(tmp, &L);
        }
        P = Next(P);
    }
    return L;
}
List sumSet(List L1, List L2)
{
    List L;
    makenullList(&L);
    Position p = L1;
    while (p->Next != NULL)
    {
        append(retrieve(p, L1), &L);
        p = Next(p);
    }
    Position q = L2;
    while (q->Next != NULL)
    {
        if (!member(retrieve(q, L2), L))
        {
            append(retrieve(q, L2), &L);
        }
        q = Next(q);
    }
    return L;
}
// ********