#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
struct Node
{
    KeyType Key;
    struct Node *Left;
    struct Node *Right;
};
typedef struct Node *Tree;

// Functions Prototype
Tree createNode(KeyType x);           // Create a Node.
void makenullTree(Tree *pT);          // Init an empty Tree.
int emptyTree(Tree T);                // Check whether Tree is empty.
Tree leftChild(Tree N);               // Return Node's Left Child if any.
Tree rightChild(Tree N);              // Return Node's Right Child if any.
int isLeaf(Tree N);                   // Check if a Node is LeafNode.
void preOrder(Tree T);                // PreOrder Tree Traversal (NLR).
void inOrder(Tree T);                 // InOrder Tree Traversal (LNR).
void posOrder(Tree T);                // PosOrder Tree Traversal (LRN).
int countNodes(Tree T);               // Count number of Nodes in a Tree.
int countLeafNodes(Tree T);           // Count Leaf Nodes
int getHeight(Tree T);                // Return Tree Height.
Tree search(KeyType x, Tree T);       // Search a Node in a Tree.
void insertNode(KeyType x, Tree *pT); // insertNode a Node.
KeyType deleteMin(Tree *pT);          // Delete Min node;
void delete (KeyType x, Tree *pT);    // Delete a specific node.
// ************

// Functions:
Tree createNode(KeyType x)
{
    Tree T = (Tree)malloc(sizeof(struct Node));
    T->Key = x;
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
        printf("%d ", T->Key);
        inOrder(T->Right); // Travel all Right Nodes.
    }
}

void posOrder(Tree T)
{
    if (!emptyTree(T))
    {
        posOrder(T->Left);  // Travel all Left Nodes.
        posOrder(T->Right); // Travel all Right Nodes.
        printf("%d ", T->Key);
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

Tree create2(KeyType v, Tree l, Tree r)
{
    Tree N = createNode(v);
    N->Left = l;
    N->Right = r;
    return N;
}

Tree search(KeyType x, Tree T)
{
    if (T == NULL)
    {
        return NULL;
    }

    else if (T->Key == x)
    {
        return T;
    }
    else if (T->Key < x)
    {
        return search(x, rightChild(T));
    }
    else
    {
        return search(x, leftChild(T));
    }
}

void insertNode(KeyType x, Tree *pT)
{
    if ((*pT) == NULL)
    {
        (*pT) = createNode(x);
    }
    else
    {
        if ((*pT)->Key > x)
        {
            insertNode(x, &(*pT)->Left);
        }
        else if ((*pT)->Key < x)
        {
            insertNode(x, &(*pT)->Right);
        }
    }
}

KeyType deleteMin(Tree *pT)
{
    if ((*pT)->Left == NULL)
    {
        // Now that (*pT) is the leftMost Node in tree.
        KeyType k = (*pT)->Key;
        (*pT) = (*pT)->Right;
        return k;
    }
    else
    {
        return deleteMin(&(*pT)->Left);
    }
}

void delete (KeyType x, Tree *pT)
{
    if ((*pT) != NULL)
    {
        if (x < (*pT)->Key)
        {
            delete (x, &(*pT)->Left);
        }
        else if (x > (*pT)->Key)
        {
            delete (x, &(*pT)->Right);
        }
        else
        {
            if (isLeaf((*pT)))
            {
                *pT = NULL;
            }
            else
            {
                if ((*pT)->Left == NULL)
                {
                    (*pT) = (*pT)->Right;
                }
                else
                {
                    if ((*pT)->Right == NULL)
                    {
                        (*pT) = (*pT)->Left;
                    }
                    else
                    {
                        (*pT)->Key = deleteMin(&(*pT)->Right);
                    }
                }
            }
        }
    }
}