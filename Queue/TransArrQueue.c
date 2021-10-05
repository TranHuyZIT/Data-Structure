#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 100

typedef int ElementType;
typedef struct
{
    ElementType Elements[MAX_LENGTH];
    int Front, Rear;
} Queue;

// Prototype
void makenullQueue(Queue *pQ); // Make null a Queue
int emptyQueue(Queue Q);       // Check if a Queue is empty
int fullQueue(Queue Q);        // Check if a Queue is full.
ElementType front(Queue Q);    // Return front element of Queue.
void deQueue(Queue *pQ);       // Delete front element from Queue.
// ******

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
    return (Q.Rear == MAX_LENGTH - 1) && (Q.Front == 0);
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
    if (emptyQueue(*pQ))
    {
        return;
    }
    else
    {
        pQ->Front++;
        if (pQ->Front > pQ->Rear)
        {
            makenullQueue(pQ);
        }
    }
}

void enQueue(ElementType x, Queue *pQ)
{
    if (!fullQueue(*pQ))
    {
        // Emty Array:
        if (emptyQueue(*pQ))
        {
            pQ->Front = 0;
        }
        // Overload Array:
        if (pQ->Rear == MAX_LENGTH - 1)
        {
            for (int i = pQ->Front; i <= pQ->Rear; i++)
            {
                pQ->Elements[i - pQ->Front] = pQ->Elements[i];
            }
            pQ->Rear = MAX_LENGTH - 1 - pQ->Front;
            pQ->Front = 0;
        }
        pQ->Rear++;
        pQ->Elements[pQ->Rear] = x;
    }
    return;
}