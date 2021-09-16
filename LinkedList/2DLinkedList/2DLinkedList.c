#include "PListLib.c"
typedef Position Column;
struct RowNode
{
    List Column;
    struct RowNode *Next;
};
typedef struct RowNode *Row;
typedef Row List2D;

void makenullList2D(List2D *pL)
{
    (*pL) = (Row)malloc(sizeof(struct RowNode));
    Column C = (Column)malloc(sizeof(struct Node));
    C->Next = NULL;
    (*pL)->Column = C;
    (*pL)->Next = NULL;
}
void readColumn(List *pL, int n)
{
    makenullList(pL); // Create An Empty List
    int i;
    Position P = *pL;
    Position N;
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
void readList2D(List2D *pL)
{
    int m, n;
    printf("Enter number of rows and columns: ");
    scanf("%d%d", &m, &n);
    makenullList2D(pL);
    Row R = (*pL);
    for (int i = 0; i < m; i++)
    {
        List Col;
        readColumn(&Col, n);
        Row nR = (Row)malloc(sizeof(struct RowNode));
        nR->Column = Col;
        nR->Next = NULL;
        R->Next = nR;
        R = R->Next;
    }
}
void printList2D(List2D L)
{
    Row R = L;
    while (R->Next != NULL)
    {
        Column C = R->Next->Column;
        while (C->Next != NULL)
        {
            printf("%d ", C->Next->Element);
            C = C->Next;
        }
        printf("\n");
        R = R->Next;
    }
}
