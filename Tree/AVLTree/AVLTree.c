#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
struct Node
{
    KeyType Key;
    int Height;
    struct Node *Left, *Right;
};
typedef struct Node *AVLTree;

AVLTree createNode(KeyType x)
{
    AVLTree T = (AVLTree)malloc(sizeof(struct Node));
    T->Key = x;
    T->Left = NULL;
    T->Right = NULL;
    return T;
}

void makenullAVLTree(AVLTree *pT)
{
    *pT = NULL;
}

int emptyAVLTree(AVLTree T)
{
    return T == NULL;
}

AVLTree leftChild(AVLTree N)
{
    if (N != NULL)
    {
        return N->Left;
    }
    return NULL;
}

AVLTree rightChild(AVLTree N)
{
    if (N != NULL)
    {
        return N->Right;
    }
    return NULL;
}

int isLeaf(AVLTree N)
{
    if (!emptyAVLTree(N))
    {
        return (leftChild(N) != NULL && rightChild(N) != NULL);
    }
    return 0;
}

void preOrder(AVLTree T)
{
}

void inOrder(AVLTree T)
{
    if (!emptyAVLTree(T))
    {
        inOrder(T->Left); // Travel all Left Nodes.
        printf("%d ", T->Key);
        inOrder(T->Right); // Travel all Right Nodes.
    }
}

void posOrder(AVLTree T)
{
    if (!emptyAVLTree(T))
    {
        posOrder(T->Left);  // Travel all Left Nodes.
        posOrder(T->Right); // Travel all Right Nodes.
        printf("%d ", T->Key);
    }
}

int countNodes(AVLTree T)
{
    if (T != NULL)
    {
        return 1 + countNodes(leftChild(T)) +
               countNodes(rightChild(T));
    }
    return 0;
}

int countLeafNodes(AVLTree T)
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
int getHeight(AVLTree T)
{
    if (T == NULL)
        return -1;
    return 1 + max(getHeight(T->Left), getHeight(T->Right));
}

AVLTree create2(KeyType v, AVLTree l, AVLTree r)
{
    AVLTree N = createNode(v);
    N->Left = l;
    N->Right = r;
    return N;
}

AVLTree search(KeyType x, AVLTree T)
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
int isAVL(AVLTree T)
{
    if (T == NULL)
    {
        return 1;
    }
    int balanceFac = getHeight(T->Left) - getHeight(T->Right);
    if (balanceFac >= -1 && balanceFac <= 1)
    {
        return 1;
    }
    return 0;
}
int getBalance(AVLTree T)
{
    if (T != NULL)
    {
        return getHeight(T->Left) - getHeight(T->Right);
    }
    return 0;
}
AVLTree leftRotate(AVLTree node)
{
    struct Node *tmp = node->Right;
    node->Right = tmp->Left;
    tmp->Left = node;
    node->Height = max(getHeight(node->Left), getHeight(node->Right)) + 1;
    tmp->Height = max(getHeight(tmp->Left), getHeight(tmp->Right)) + 1;
    return tmp;
}
AVLTree rightRotate(AVLTree node)
{
    struct Node *tmp = node->Left;
    node->Left = tmp->Right;
    tmp->Right = node;
    node->Height = max(getHeight(node->Left), getHeight(node->Right)) + 1;
    tmp->Height = max(getHeight(tmp->Left), getHeight(tmp->Right)) + 1;
    return tmp;
}
AVLTree rightleftRotate(AVLTree node)
{
    node->Right = rightRotate(node->Right);
    return leftRotate(node);
}
AVLTree leftrightRotate(AVLTree T)
{
    T->Left = leftRotate(T->Left);
    return rightRotate(T);
}
AVLTree insertNode(KeyType key, AVLTree T)
{
    if (T == NULL)
    {
        T = (AVLTree)malloc(sizeof(struct Node));
        T->Key = key;
        T->Left = NULL;
        T->Right = NULL;
    }
    else if (key < T->Key)
    {
        T->Left = insertNode(key, T->Left);
    }
    else if (key > T->Key)
    {
        T->Right = insertNode(key, T->Right);
    }
    else
    {
        return T;
    }
    T->Height = 1 + max(getHeight(T->Left), getHeight(T->Right));
    int balance = getBalance(T);
    if (balance > 1 && key < T->Left->Key)
    {
        return rightRotate(T);
    }
    else if (balance < -1 && key > T->Right->Key)
    {
        return leftRotate(T);
    }
    else if (balance > 1 && key > T->Left->Key)
    {
        return leftrightRotate(T);
    }
    if (balance < -1 && key < T->Right->Key)
    {
        return rightleftRotate(T);
    }
    return T;
}