#ifndef QUEUE_H
#define QUEUE_H

#include "Linkedlist.h"

typedef int Data;

struct Queue{
	struct linked_Node* front;
	struct linked_Node* rear;
};

struct Queue* InitQueue();
void DestoryQueue(struct Queue* Q1);
void ClearQueue(struct Queue* Q1);
int	isEmpty(struct Queue* Q1);
Data GetFront(struct Queue* Q1);
void EnQueue(struct Queue* Q1,Data D1);
Data DeQueue(struct Queue* Q1);
//static int Pointer2Number(struct  Queue* Q1,Data* D1);

#endif

