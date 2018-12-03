#include "queue.h"

#define Queue_Init_Size 50

struct Queue* InitQueue()
{
	struct Queue* Q1 = (struct Queue*)malloc(sizeof(struct Queue));
	struct linked_Node* Newnode = Creat_Node(NULL);
	if(Q1 == NULL) return NULL;
	Q1->front = Newnode;
	Q1->rear = Newnode;
	return Q1;
} 

void DestoryQueue(struct Queue* Q1)
{
	while(!isEmpty(Q1)) DeQueue(Q1);
	free(Q1);
}

void ClearQueue(struct Queue* Q1)
{
	while(!isEmpty(Q1)) DeQueue(Q1);
}

int	isEmpty(struct Queue* Q1)
{
	return Q1->front == Q1->rear;
}

Data GetFront(struct Queue* Q1)
{
	if(isEmpty(Q1)) return NULL;
	return Q1->front->next->elem;
}

void EnQueue(struct Queue* Q1,Data D1)
{
	struct linked_Node* Newnode = Creat_Node(D1);
	if(Newnode == NULL) return NULL;
	Q1->rear->next = Newnode;
	Q1->rear = Newnode;
}

Data DeQueue(struct Queue* Q1)
{
	struct linked_Node* Newnode = Q1->front->next;
	Data Newdata = Newnode->elem;
	if(isEmpty(Q1)) return NULL;
	Q1->front->next = Newnode->next;
	Newnode->next = NULL;
	if(Newnode == Q1->rear) Q1->rear = Q1->front;
	free(Newnode);
	return Newdata;
}




