#include <stdio.h>
#include <stdlib.h>

// Definitions
typedef int ElementType;
struct Node
{
    ElementType Data;
    struct Node *Left, *Right;
};
typedef struct Node *Tree;

// Functions Prototype
Tree createNode(ElementType x);       // Create a Node.
void makenullTree(Tree *pT);          // Init an empty Tree.
int emptyTree(Tree T);                // Check whether Tree is empty.
Tree leftChild(Tree N);               // Return Node's Left Child if any.
Tree rightChild(Tree N);              // Return Node's Right Child if any.
int isLeaf(Tree N);                   // Check if a Node is LeafNode.
void preOrder(Tree T);                // PreOrder Tree Traversal (NLR).
void inOrder(Tree T);                 // InOrder Tree Traversal (LNR).
void posOrder(Tree T);                // PosOrder Tree Traversal (LRN).
int countNodes(Tree T);               // Count number of Nodes in a Tree.
Tree search(ElementType x, Tree T);   // Search a Node in a Tree.
void insert(ElementType x, Tree *pT); // Insert a Node.
// ************

// Functions:
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
    if (N != NULL)
    {
        return (leftChild(N) != NULL && rightChild(N) != NULL);
    }
    return 0;
}

void preOrder(Tree T)
{
    printf("%d ", T->Data);
    if (leftChild(T) != NULL)
    {
        preOrder(T->Left); // Travel all Left Nodes.
    }
    if (rightChild(T) != NULL)
    {
        preOrder(T->Right); // Travel all Right Nodes.
    }
}

void inOrder(Tree T)
{
    if (leftChild(T) != NULL)
    {
        inOrder(T->Left);
    }
    printf("%d ", T->Data);
    if (rightChild(T) != NULL)
    {
        inOrder(T->Right);
    }
}

void posOrder(Tree T)
{
    if (leftChild(T) != NULL)
    {
        posOrder(T->Left);
    }
    if (rightChild(T) != NULL)
    {
        posOrder(T->Right);
    }
    printf("%d ", T->Data);
}

int countNodes(Tree T)
{
    if (T != NULL)
    {
        return 1 + countNodes(leftChild(T)) + countNodes(rightChild(T));
    }
}

Tree search(ElementType x, Tree T)
{
    if (T == NULL)
    {
        return NULL;
    }

    else if (T->Data == x)
    {
        return T;
    }
    else if (T->Data < x)
    {
        return search(x, leftChild(T));
    }
    else
    {
        return search(x, rightChild(T));
    }
}

Tree createNode(ElementType x)
{
    Tree T = (Tree)malloc(sizeof(struct Node));
    T->Data = x;
    T->Left = NULL;
    T->Right = NULL;
    return T;
}

void insert(ElementType x, Tree *pT)
{
    if ((*pT) == NULL)
    {
        (*pT) = createNode(x);
    }
    else
    {
        if ((*pT)->Data > x)
        {
            insert(x, &(*pT)->Left);
        }
        else if ((*pT)->Data < x)
        {
            insert(x, &(*pT)->Right);
        }
    }
}