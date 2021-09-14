#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "PListLib.c"

// khoi tao Stack bang LinkedList
typedef List Stack;

// *******

// prototypes:
void makenullStack(Stack *pS) 		// khoi tao Stack rong
int emptyStack(Stack S) 			// kiem tra Stack rong
int emptyStack(Stack S) 			// kiem tra Stack rong
ElementType top(Stack S) 			// tra ve p.tu o dinh Stack
void pop(Stack *pS) 				// xoa p.tu tai dinh Stack
void push(Elementtype x, Stack *pS) // them p.tu vao dinh Stack
void printStack(Stack S) 			// in cac p.tu trong Stack

// *******

// function:

void makenullStack(Stack *pS)
{
	makenullList(pS);
}

int emptyStack(Stack S)
{
	return emptyList(S);
}

ElementType top(Stack S)
{
	retrieve(first(S),S);
}

void pop(Stack *pS)
{
	deleteList(first(*pS), pS);
}

void push(Elementtype x, Stack *pS)
{
	insertList(x, first(*pS), pS);
}

void printStack(Stack S)
{
	printList(S);
}