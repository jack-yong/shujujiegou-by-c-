#include "Linkedlist.h"

struct linked_list* init()
{
	struct linked_list * p = (struct linked_list *)malloc(sizeof(struct linked_list));
	if(p == NULL)
	{
		return NULL;
	}
	p->head = NULL;
	return p;
}

void Destory(struct linked_list * list)
{
	struct linked_Node* N_node = list->head;
	while(list->head)
	{
		N_node = list->head->next;
		free(list->head);
		list->head = N_node;
	}
	free(list);
}

int is_empty(struct linked_list * list)
{
	return list->head == NULL;
}

void Clear(struct linked_list * list )
{
	struct linked_Node* N_node;
	while(list->head)
	{
	    N_node = list->head->next;
		free(list->head);
		list->head = N_node; 
	}
}

int list_length(struct linked_list* list)
{
	struct linked_Node* N_node = list->head;
	int count = 0;
	while(N_node)
	{
		count++;
		N_node = N_node->next;
	} 
	return count;
}

struct linked_Node * list_get_node(struct linked_list* list,int index)
{
	struct linked_Node* N_node = list->head;
	int count = 0;
	while(N_node)
	{
		if(++count == index)
		{
			return N_node;
		}
		N_node =N_node->next;
	}
	return NULL;
}

int list_find(struct linked_list* list,data elem)
{
	struct linked_Node* N_node = list->head;
	int count = 1;
	while(N_node)
	{
		if((int)N_node->elem == (int)elem)
		{
			return count;	
		}
		N_node = N_node->next;
		count++;
	}
	return NULL;
}

struct linked_Node * Creat_Node(data elem)
{
	struct linked_Node* N_node =(struct linked_Node *)malloc(sizeof(struct linked_Node));
	if(N_node == NULL)
	{
		return NULL;
	}
	N_node->elem = elem;
	N_node->next = NULL;
	return N_node;
}

struct linked_Node * insert_after(struct linked_Node * node ,data elem)
{
	struct linked_Node*  N_node = Creat_Node(elem);
	if(!N_node)
	{
		return NULL;
	}
	N_node->next = node->next;
	node->next = N_node;
	return N_node;
}

struct linked_Node * insert(struct linked_list * list,const int index,data elem)
{
	struct linked_Node* N_node = Creat_Node(elem);
	int isempty = is_empty(list);
	int count = list_length(list);
	if(isempty)
	{
		if(index == 1)
		{
			list->head = N_node;
			return N_node;
		}
		else{
			return NULL;
		}
	}	
	else
	{
		if(index == 1)
		{
			N_node->next = list->head;
			list->head = N_node;
			return N_node;
		}
		else if(index > 0 && index <= count+1)
		{
			struct linked_Node* after_node;
			after_node = list_get_node(list,index-1);
			return insert_after(after_node,elem);
		}
		return NULL;
	}
}

struct linked_Node * Remove_after(struct linked_Node * node)
{
	struct linked_Node* N_node = node->next;
	node->next = N_node->next;
	N_node->next = NULL;
	return N_node;
}

struct linked_Node * Remove_first(struct linked_list* list)
{
	struct linked_Node* N_node = list->head;
	list->head = N_node->next;
	N_node->next = NULL;
	return N_node;
}

struct linked_Node * Remove(struct linked_list* list,int index)
{
	struct linked_Node* N_node = list_get_node(list,index-1);
	if(index == 1)
	{
		return Remove_first(list);
	}
	if(N_node == NULL)
	{
		return NULL;
	}
	return Remove_after(N_node);
}

static void asses(struct linked_Node* node)
{
	printf("%d,",node->elem);
}

void travers(struct linked_list* list)
{
	struct linked_Node* N_node = list->head;
	while(N_node)
	{
		asses(N_node);
		N_node = N_node->next;
	}
}


