#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<stdio.h>
#include<stdlib.h>

typedef int data;

struct linked_Node {

	struct linked_Node* next;
	data elem;
};

struct linked_list{
	struct linked_Node* head;
};

struct linked_list* init();
void Destory(struct linked_list * list);
int is_empty(struct linked_list * list);
void Clear(struct linked_list * list );
int list_length(struct linked_list* list);
struct linked_Node * list_get_node(struct linked_list* list,int index);
int list_find(struct linked_list* list,data elem);
struct linked_Node * Creat_Node(data elem);
struct linked_Node * insert_after(struct linked_Node * node ,data elem);
struct linked_Node * insert(struct linked_list * list,const int index,data elem);
struct linked_Node * Remove_after(struct linked_Node * node);
struct linked_Node * Remove_first(struct linked_list* list);
struct linked_Node * Remove(struct linked_list* list,int index);
static void asses(struct linked_Node* node);
void travers(struct linked_list* list);


#endif


