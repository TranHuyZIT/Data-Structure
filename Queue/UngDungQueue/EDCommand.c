#include "TransArrQueue.c"
int main()
{
    int n;
    scanf("%d%*c", &n);
    Queue Q;
    makenullQueue(&Q);
    for (int i = 0; i < n; i++)
    {
        char c;
        scanf("%c", &c);
        if (c == 'E')
        {
            int tmp;
            scanf("%d%*c", &tmp);
            enQueue(tmp, &Q);
            printf("%d\n", Q.Rear - Q.Front + 1);
        }
        else if (c == 'D')
        {
            scanf("%*c");
            printf("%d ", emptyQueue(Q) == 1 ? -1 : front(Q));
            deQueue(&Q);
            printf("%d\n", emptyQueue(Q) == 1 ? 0 : Q.Rear - Q.Front + 1);
        }
    }
    return 0;
}