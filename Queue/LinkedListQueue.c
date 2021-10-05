#include <stdio.h>
#include <stdlib.h>

// Definitions
typedef int ElementType;
struct Node
{
    ElementType Element;
    struct Node *Next;
};
typedef struct Node *Position;
typedef struct
{
    Position Front, Rear;
} Queue;
// ******

void makenullQueue(Queue *pQ)
{
    Position Header = (Position)malloc(sizeof(struct Node));
    Header->Next = NULL;
    pQ->Front = Header;
    pQ->Rear = Header;
}

int emptyQueue(Queue Q)
{
    return Q.Rear == Q.Front;
}

ElementType front(Queue Q)
{
    if (!emptyQueue(Q))
    {
        return (Q.Front)->Next->Element;
    }
}

void enQueue(ElementType x, Queue *pQ)
{
    Position N = (Position)malloc(sizeof(struct Node));
    N->Element = x;
    N->Next = NULL;
    pQ->Rear->Next = N;
    pQ->Rear = N;
}