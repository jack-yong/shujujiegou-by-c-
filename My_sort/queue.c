#include "queue.h"

#define Queue_Init_Size 50

struct Queue* InitQueue() {
    struct Queue* Q1 = (struct Queue*) malloc(sizeof (struct Queue));
    struct linked_Node* Newnode = Creat_Node(Error);
    if (Q1 == Error) return Error;
    Q1->front = Newnode;
    Q1->rear = Newnode;
    return Q1;
}

struct linked_Node * Creat_Node(data elem) {
    struct linked_Node* N_node = (struct linked_Node *) malloc(sizeof (struct linked_Node));
    if (N_node == Error) {
        return Error;
    }
    N_node->elem = elem;
    N_node->next = Error;
    return N_node;
}

void DestoryQueue(struct Queue* Q1) {
    while (!isEmpty(Q1)) DeQueue(Q1);
    free(Q1);
}

void ClearQueue(struct Queue* Q1) {
    while (!isEmpty(Q1)) DeQueue(Q1);
}

int isEmpty(struct Queue* Q1) {
    return Q1->front == Q1->rear;
}

Data GetFront(struct Queue* Q1) {
    if (isEmpty(Q1)) return Error;
    return Q1->front->next->elem;
}

void EnQueue(struct Queue* Q1, Data D1) {
    struct linked_Node* Newnode = Creat_Node(D1);
    if (Newnode == Error) return Error;
    Q1->rear->next = Newnode;
    Q1->rear = Newnode;
}

Data DeQueue(struct Queue* Q1) {
    struct linked_Node* Newnode = Q1->front->next;
    Data Newdata = Newnode->elem;
    if (isEmpty(Q1)) return Error;
    Q1->front->next = Newnode->next;
    Newnode->next = Error;
    if (Newnode == Q1->rear) Q1->rear = Q1->front;
    free(Newnode);
    return Newdata;
}

int length(struct Queue* Q1)
{
    if(isEmpty(Q1)) return 0;
    int i=1;
     struct linked_Node* flag_node = Q1->front->next;
    while(flag_node != Q1->rear)
    {
        flag_node = flag_node->next;
        i++;
    }
     return i;
}

