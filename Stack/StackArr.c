#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// khoi tao Stack
#define MaxLength 100

typedef int ElementType;

typedef struct
{
	ElementType Elements[MaxLength];

	int Top_idx;
} Stack;

// *******

// prototypes:

void makenullStack(Stack *pS);		 // khoi tao Stack rong
int emptyStack(Stack S);			 // kiem tra Stack rong
int full(Stack S);					 // kiem tra Stack day
ElementType top(Stack S);			 // tra ve p.tu tai dinh Stack
void pop(Stack *pS);				 // xoa p.tu tai dinh Stack
void push(ElementType x, Stack *pS); // them p.tu vao dinh Stack
void printStack(Stack S);			 // in tat ca p.tu co trong Stack
void readStack(Stack *pS);			 // nhap Stack tu ban phim

// *******

// functions:

void makenullStack(Stack *pS)
{
	pS->Top_idx = MaxLength;
}

int emptyStack(Stack S)
{
	return S.Top_idx == MaxLength;
}

int full(Stack S)
{
	return S.Top_idx == 0;
}

ElementType top(Stack S)
{
	// neu Stack rong -> loi
	if (emptyStack(S))
	{
		printf("Stack is empty\n");
	}
	else
	{
		return S.Elements[S.Top_idx];
	}
}

void pop(Stack *pS)
{
	// neu Stack rong -> loi
	if (emptyStack(*pS))
	{
		printf("Stack is empty\n");
	}
	else
	{
		pS->Top_idx = pS->Top_idx + 1;
	}
}

void push(ElementType x, Stack *pS)
{
	// neu Stack day -> loi
	if (full(*pS))
	{
		printf("Stack is full\n");
	}
	else
	{
		pS->Top_idx = pS->Top_idx - 1;
		pS->Elements[pS->Top_idx] = x;
	}
}

void printStack(Stack S)
{
	// neu Stack day -> loi
	if (emptyStack(S))
	{
		printf("Stack is empty\n");
	}
	else
	{
		for (int i = S.Top_idx; i < MaxLength; i++)
		{
			printf("%d ", S.Elements[i]);
		}
	}
	printf("\n");
}

void readStack(Stack *pS)
{
	makenullStack(pS);

	int n;
	scanf("%d", &n);

	for (int i = MaxLength - 1; i >= MaxLength - n; i--)
	{
		scanf("%d", &pS->Elements[i]);
		pS->Top_idx--;
	}
}

int main()
{
	Stack S;
	readStack(&S);
	printStack(S);
	return 0;
}