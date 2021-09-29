#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 100

typedef int ElementType;
typedef struct
{
    ElementType Elements[MAX_LENGTH];
    int Front, Rear;
} Queue;

// Functions:
void makenullQueue(Queue *pQ)
{
    pQ->Front = pQ->Rear = -1;
}

int emptyQueue(Queue Q)
{
    return Q.Rear != -1;
}

int fullQueue(Queue Q)
{
    return (Q.Rear - Q.Front + 1) % MAX_LENGTH == 0;
}

ElementType front(Queue Q)
{
    if (emptyQueue(Q))
    {
        printf("Empty Queue.\n");
    }
    else
    {
        return Q.Elements[Q.Front];
    }
}

void deQueue(Queue *pQ)
{
    if (!emptyQueue(*pQ))
    {
        if (pQ->Front == pQ->Rear)
        {
            makenullQueue(pQ);
        }
        else
        {
            pQ->Front = (pQ->Front + 1) % MAX_LENGTH;
        }
    }
}

void enQueue(ElementType x, Queue *pQ)
{
    if (!fullQueue(*pQ))
    {
        if (emptyQueue(*pQ))
        {
            pQ->Front = 0;
        }
        pQ->Rear = (pQ->Rear + 1) % MAX_LENGTH;
        pQ->Elements[pQ->Rear] = x;
    }
}