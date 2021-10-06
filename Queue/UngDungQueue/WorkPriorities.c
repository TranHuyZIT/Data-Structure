#include "TransArrQueue.c"
int main()
{
    // Read Input
    Queue Q;
    makenullQueue(&Q);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        enQueue(tmp, &Q);
    }
    int Priority[MaxLength];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Priority[i]);
    }

    // Solve
    int idx = 0;
    int task = 0;
    int top;
    while (!emptyQueue(Q))
    {
        if (!emptyQueue(Q))
        {
            top = front(Q);
        }
        if (top == Priority[idx])
        {
            deQueue(&Q);
            task++;
            idx++;
        }
        else
        {
            deQueue(&Q);
            enQueue(top, &Q);
            task++;
        }
    }
    printf("%d", task);
}