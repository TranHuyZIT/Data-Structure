#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Definitions
typedef struct
{
    char ID[10];
    char Name[50];
    float R1, R2, R3;
} Student;
typedef Student ElementType;

struct Node
{
    ElementType Element;
    struct Node *Next;
};
typedef struct Node *Position;
typedef Position List;

// ******

// Prototypes
List getList();
Position locate(char ID[], List L);
List readList();
int append(Student s, List *pL);
List getFailedList(List L);
void showPassedList(List L);

// Functions:
List getList()
{
    Position N = (Position)malloc(sizeof(struct Node));
    N->Next = NULL;
    return N;
}
Position locate(char ID[], List L)
{
    Position p = L;
    while (p->Next != NULL)
    {
        if (strcmp(p->Element.ID, ID) == 0)
        {
            break;
        }
        p = p->Next;
    }
    return p;
}

int append(Student s, List *pL)
{
    struct Node *end = *pL;
    while (end->Next != NULL)
    {
        end = end->Next;
    }
    if (locate(s.ID, *pL) == end)
    {
        struct Node *N = (struct Node *)malloc(sizeof(struct Node));
        N->Element = s;
        N->Next = NULL;
        end->Next = N;
        return 1;
    }
    else
    {
        return 0;
    }
}
List readList()
{
    int n, i;
    Student s;
    char st[50];
    List L = getList(); // Khởi tạo danh sách rỗng
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf(" "); //skip some characters
        fgets(st, 10, stdin);
        if (st[strlen(st) - 1] == '\n')
            st[strlen(st) - 1] = '\0';
        strcpy(s.ID, st);
        fgets(st, 50, stdin);
        if (st[strlen(st) - 1] == '\n')
            st[strlen(st) - 1] = '\0';
        strcpy(s.Name, st);
        scanf("%f%f%f", &s.R1, &s.R2, &s.R3);
        // Nếu mã sinh viên chưa có thì chèn vào danh sách
        struct Node *end = L;
        while (end->Next != NULL)
        {
            end = end->Next;
        }

        if (locate(s.ID, L) != end)
        {
            printf("%s exists\n", s.ID);
        }
        else
        {
            append(s, &L);
        }
    }
    return L;
}
List getFailedList(List L)
{
    List F = getList();
    struct Node *p = L;
    while (p->Next != NULL)
    {
        Student sv = p->Next->Element;
        float tb = (sv.R1 + sv.R2 + sv.R3) / 3;
        if (tb < 4)
        {
            append(sv, &F);
        }
        p = p->Next;
    }
    return F;
}
void showPassedList(List L)
{
    struct Node *p = L;
    int stt = 1;
    while (p->Next != NULL)
    {
        Student sv = p->Next->Element;
        float tb = (sv.R1 + sv.R2 + sv.R3) / 3;
        if (tb >= 4)
        {
            printf("%2d -%11s -%51s - %.3f - %.3f - %.3f - %.3f\n", stt, sv.ID, sv.Name, sv.R1, sv.R2, sv.R3, tb);
            stt++;
        }
        p = p->Next;
    }
    printf("%d students in total", stt - 1);
}