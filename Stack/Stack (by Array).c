# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

// do dai toi da cua Stack
#define MaxLength 100

// kieu p.tu
typedef int ElementType;

// khoi tao Stack
typedef struct{
	/*dung Array de luu tru
	cac p.tu*/
	ElementType Elements[MaxLength];

	// dinh cua Stack
	int Top_idx;
}Stack;

// khoi tao Stack rong
void makenullStack(Stack *pS){
	pS->Top_idx = MaxLength;
}

// kiem tra Stack rong
int emptyStack(Stack S){
	return S.Top_idx == MaxLength;
}

// kiem tra Stack day
int full(Stack S){
	return S.Top_idx == 0;
}

// tra ve p.tu tai dinh Stack
ElementType top(Stack S){
	// neu Stack rong -> loi
	if (emptyStack(S)){
		printf("Stack is empty bitch!\n");
	}
	else{
		return S.Elements[S.Top_idx];
	}
}

// xoa p.tu tai dinh Stack
void pop(Stack *pS){
	// neu Stack rong -> loi
	if (emptyStack(*pS)){
		printf("Stack is empty bitch!\n");
	}
	else{
		pS->Top_idx = pS->Top_idx +1;
	}
}

// them p.tu vao dinh Stack
void push(ElementType x, Stack *pS){
	// neu Stack day -> loi
	if (full(*pS)){
		printf("Stack is full bitch!\n");
	}
	else{
		pS->Top_idx = pS->Top_idx-1;
		pS->Elements[pS->Top_idx] = x;
	}
}

// in tat ca p.tu co trong Stack
void printStack(Stack S){
	// neu Stack day -> loi
	if (emptyStack(S)){
		printf("Stack is empty bitch!\n");
	}
	else{
		for (int i=S.Top_idx; i<MaxLength; i++){
			printf("%d ", S.Elements[i]);
		}
	}
	printf("\n");
}

// nhap Stack tu ban phim
void readStack(Stack *pS){
	makenullStack(pS);

	int n;
	scanf("%d", &n);

	for (int i=MaxLength-1; i>=MaxLength-n; i--){
		scanf("%d", &pS->Elements[i]);
		pS->Top_idx--;
	}
}