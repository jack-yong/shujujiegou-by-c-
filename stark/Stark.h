#ifndef STARK_H
#define STARK_H

#include <stdio.h>
#include <stdlib.h>
typedef int Data;

struct Operator{
	char * sign;
	int count;
};

struct kuo_hao{
	char * sign;
	int flag;
};

struct Stark{
	Data* base;
	Data* top;
	int stacksize;
};

struct Stark* StarkInit(); 
void Destory(struct Stark* S1);
void Clear(struct Stark* S1);
int isEmpty(struct Stark* S1);
int Length(struct Stark* S1);
int Gettop(struct Stark* S1);
void Push(struct Stark* S1,Data elem);
int Pop(struct Stark* S1);
void Visit(Data elem);
void Traverse(struct Stark* S1);

#endif
