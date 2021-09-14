#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "PListLib.c"

// khoi tao Stack bang LinkedList
typedef List Stack;

// khoi tao Stack rong
void makenullStack(Stack *pS)
{
	makenullList(pS);
}

// kiem tra Stack rong
int emptyStack(Stack S)
{
	return emptyList(S);
}

// tra ve p.tu o dinh Stack
ElementType top(Stack S)
{
	retrieve(first(S), S);
}

// xoa p.tu tai dinh Stack
void pop(Stack *pS)
{
	deleteList(first(*pS), pS);
}

// them p.tu vao dinh Stack
void push(ElementType x, Stack *pS)
{
	insertList(x, first(*pS), pS);
}

// in cac p.tu trong Stack
void printStack(Stack S)
{
	printList(S);
}

// nhap Stack tu ban phim
void readStack(Stack *pS)
{
	// tao chua lam ok ?
}