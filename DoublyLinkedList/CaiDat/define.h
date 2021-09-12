#include <stdio.h>
#include <stdlib.h>
typedef int ElementType; // define ElementType inside a Node.
struct Node
{
    ElementType Element; // Store Element
    struct Node *Pre;   // Pointer to previous node.
    struct Node *Next;   // Pointer to next node.
};

typedef struct Node *Position;
struct List // Define a List
{
    //List will store 2 position Head and Tail for better access and control.
    Position Head;
    Position Tail;
} List;
typedef struct List *pList; // pList: Pointer to struct List
