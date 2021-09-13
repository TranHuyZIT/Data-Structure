#include <stdio.h>
#include <stdlib.h>
typedef int ElementType; // define ElementType inside a Node.
struct Node
{
    ElementType Element; // Store Element
    struct Node *Pre;    // Pointer to previous node.
    struct Node *Next;   // Pointer to next node.
};

typedef struct Node *Position;
struct list // Define a List
{
    //List will store 2 position Head and Tail for better access and control.
    Position Head;
    Position Tail;
    // Head is an empty Position, while Tail store data.
};
typedef struct list List;
typedef List *pList; // pList: Pointer to struct List
