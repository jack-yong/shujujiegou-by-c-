#include "Stark.h"

#define Stack_Init_Size 50
#define Stack_Add_Size 10

struct Stark* StarkInit()
{
	struct Stark* S1 = (struct Stark*)malloc(sizeof(struct Stark));
	S1->base = (Data*)malloc(Stack_Init_Size * sizeof(Data));
	if(!S1->base)
		return NULL;
	S1->top = S1->base;
	S1->stacksize = Stack_Init_Size;
	return S1;
}

void Destory(struct Stark* S1)
{
	free(S1->base);
	free(S1);
}

void Clear(struct Stark* S1)
{
	S1->top = S1->base;
}

int isEmpty(struct Stark* S1)
{
	if(S1->top == S1->base)
		return 1;
	return 0;
}

int Length(struct Stark* S1)
{
	int count = 0;
	int * Newpointer = S1->top;
	if(isEmpty(S1))
		return 0;
	do
	{
		count++;
		Newpointer--;
	}while(Newpointer == S1->base);
	return count;
}

int Gettop(struct Stark* S1)
{
	if(isEmpty(S1))
		return NULL;
	return *(S1->top-1);
}

void Push(struct Stark* S1,int elem)
{
	if(Length(S1) >= S1->stacksize)
	{
		S1->base = (Data*)realloc(S1->base,(Stack_Init_Size+Stack_Add_Size)* sizeof(Data));
		S1->top = S1->base + Stack_Init_Size;
		S1->stacksize += Stack_Add_Size;
	}
	* S1->top = elem;
	S1->top++;		
}

int Pop(struct Stark* S1)
{
	if(isEmpty(S1))
		return NULL;
	return *(--S1->top);
}

void Visit(Data elem)
{
	printf("%d",elem);
}

void Traverse(struct Stark* S1)
{
	if(Length(S1) == 0)
		return NULL;
	do
	{
		Pop(S1);
	}while(isEmpty(S1));
	S1->top += Length(S1);
}

