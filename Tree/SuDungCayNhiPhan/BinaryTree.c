#include <stdio.h>
#include <stdlib.h>

// Definitions
typedef int DataType;
struct Node
{
    DataType Data;
    struct Node *Left, *Right;
};
typedef struct Node *Tree;

// Functions Prototype
Tree createNode(DataType x); // Create a Node.
void makenullTree(Tree *pT); // Init an empty Tree.
int emptyTree(Tree T);       // Check whether Tree is empty.
Tree leftChild(Tree N);      // Return Node's Left Child if any.
Tree rightChild(Tree N);     // Return Node's Right Child if any.
int isLeaf(Tree N);          // Check if a Node is LeafNode.
void preOrder(Tree T);       // PreOrder Tree Traversal (NLR).
void inOrder(Tree T);        // InOrder Tree Traversal (LNR).
void posOrder(Tree T);       // PosOrder Tree Traversal (LRN).
int countNodes(Tree T);      // Count number of Nodes in a Tree.
int countLeafNodes(Tree T);  // Count Leaf Nodes
int getHeight(Tree T);       // Return Tree Height.
// ************

// Functions:
Tree createNode(DataType x)
{
    Tree T = (Tree)malloc(sizeof(struct Node));
    T->Data = x;
    T->Left = NULL;
    T->Right = NULL;
    return T;
}

void makenullTree(Tree *pT)
{
    *pT = NULL;
}

int emptyTree(Tree T)
{
    return T == NULL;
}

Tree leftChild(Tree N)
{
    if (N != NULL)
    {
        return N->Left;
    }
    return NULL;
}

Tree rightChild(Tree N)
{
    if (N != NULL)
    {
        return N->Right;
    }
    return NULL;
}

int isLeaf(Tree N)
{
    if (!emptyTree(N))
    {
        return (leftChild(N) != NULL && rightChild(N) != NULL);
    }
    return 0;
}

void preOrder(Tree T)
{
}

void inOrder(Tree T)
{
    if (!emptyTree(T))
    {
        inOrder(T->Left); // Travel all Left Nodes.
        printf("%d ", T->Data);
        inOrder(T->Right); // Travel all Right Nodes.
    }
}

void posOrder(Tree T)
{
    if (!emptyTree(T))
    {
        posOrder(T->Left);  // Travel all Left Nodes.
        posOrder(T->Right); // Travel all Right Nodes.
        printf("%d ", T->Data);
    }
}

int countNodes(Tree T)
{
    if (T != NULL)
    {
        return 1 + countNodes(leftChild(T)) +
               countNodes(rightChild(T));
    }
    return 0;
}

int countLeafNodes(Tree T)
{
    if (T == NULL)
        return 0;
    else if (isLeaf(T))
        return 1;
    else
    {
        return countLeafNodes(leftChild(T)) + countLeafNodes(rightChild(T));
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}
int getHeight(Tree T)
{
    if (T == NULL)
        return -1;
    return 1 + max(getHeight(T->Left), getHeight(T->Right));
}

Tree create2(DataType v, Tree l, Tree r)
{
    Tree N = createNode(v);
    N->Left = l;
    N->Right = r;
    return N;
}

int main()
{
    Tree T = NULL;
    Tree p;
    int x;

    insert(27, &T);
    insert(12, &T);
    insert(40, &T);
    insert(4, &T);
    insert(20, &T);
    insert(34, &T);
    insert(30, &T);
    insert(50, &T);
    delete (40, &T);
    inOrder(T);
}