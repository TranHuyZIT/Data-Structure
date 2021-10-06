#include <stdio.h>
#include <stdlib.h>
#include "PIQueue.c"

int minPos(int a[], int n)
{
    int min = a[1];
    int k = 1;
    for (int i = 2; i < n; i++)
        if (min > a[i])
        {
            min = a[i];
            k = i;
        }
    return k;
}

int main()
{
    int soKH, maxQuay, tbGiaoDich, tbDiChuyen, X;
    scanf("%d%d%d%d%d", &soKH, &maxQuay, &tbGiaoDich, &tbDiChuyen, &X);

    int tgQuay[maxQuay + 1];
    int soQuayMo = 1;
    Queue Q;
    int tongTG;
    while (soQuayMo <= maxQuay)
    {
        // Reset time.
        for (int j = 0; j <= soQuayMo; j++)
        {
            tgQuay[j] = 0;
        }
        // enQueue.
        makenullQueue(&Q);
        for (int i = 1; i <= soKH; i++)
        {
            enQueue(tbDiChuyen * i, &Q);
        }
        // Tinh tong tg:
        tongTG = 0;
        while (!emptyQueue(Q))
        {
            for (int i = 1; i <= soQuayMo; i++)
            {
                if (!emptyQueue(Q))
                {
                    if (tgQuay[i] == 0)
                        tgQuay[i] = front(Q);
                    tongTG += tgQuay[i] - front(Q) + tbGiaoDich;
                    tgQuay[i] += tbGiaoDich;
                    deQueue(&Q);
                }
            }
        }
        printf("So quay: %d; Thoi gian cho trung binh: %d.0\n", soQuayMo, tongTG / soKH);
        if ((float)tongTG / soKH <= X)
        {
            printf("=> Sieu thi se mo %d quay", soQuayMo);
            return 0;
        }
        soQuayMo++;
    }
    printf("Voi %d quay hien co, khach phai cho it nhat %.1f giay moi duoc phuc vu.", maxQuay, (float)tongTG / soKH);
    return 0;
}