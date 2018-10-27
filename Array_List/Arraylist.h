#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H
#include <stdio.h>
#include <stdlib.h>

#define index2prepos 2
#define LISTINCREMENT 10

static int i=0;

typedef int data;
struct Array_List {
		data*  array;
		int capcity;
		int pos;
	};
	
struct Array_List* init(int capacity){
	struct	Array_List* p = malloc(sizeof(struct Array_List));
	if(p == NULL)
	{
		return NULL;
	}
	p->array = (data*)malloc(capacity * sizeof(data));
	if(p->array == NULL)
	{
		return NULL;
	}
	p->capcity = capacity;
	p->pos = 0;
	return p;
	
} 

void Destory(struct Array_List* list)
{
	free(list->array);
	free(list);
}

int is_empty(struct Array_List * list)
{
	return list->pos == 0;
}

void Clear(struct Array_List * list)
{
	list->pos == 0;
}

int Length(struct Array_List* list)
{
	return list->pos;
}

static int Get_logic_index(int index)
{
	return index-1;
}

data GetElem(struct Array_List* list ,int index)
{
	if(index < 1 || index > (list->pos))
	{
		return NULL;
	}
	return  list->array[Get_logic_index(index)];
}

static int Compare(data d1,data d2)
{
	int F_data = (int)d1;
	int S_data = (int)d2;
	if(F_data > S_data)
		return -1;
	else if(F_data == S_data)
		return 0;
	else if(F_data < F_data)
		return 1;
	
}

int Find(struct Array_List* list,data element)
{
	for(i=0;i<list->pos;i++)
	{
		if(!Compare(element,list->array[i]))
		{
			return i+1;
		}
	}
	return NULL;
}

data Priorelem(struct Array_List* list,data element)
{
	if(Find(list,element) == 1)
		return NULL;
	else
	{
		return list->array[Find(list,element)-index2prepos];
	} 
}

data Nextelem(struct Array_List* list,data element)
{
	if(Find(list,element) == list->pos)
		return NULL;
	else
	{
		return list->array[Find(list,element)];
	}
}

int Listinsert(struct Array_List* list,data element,int index)
{
	int p = Get_logic_index(index);
	if(list->pos >= list->capcity);
	{
		list->array = (data*)realloc(list->array, (list->capcity + LISTINCREMENT)*sizeof(data));
		list->capcity += LISTINCREMENT;
	}
	for( i=list->pos;i>=p;i--)
	{
		list->array[i+1] = list->array[i];
	}
	list->array[p] = element;
	list->pos++;
	return 1;
}

int Append_List(struct Array_List* list,data element)
{
	int textpos; 
	if (list->pos >= list->capcity)
	{
		list->array = (data*)realloc(list->array, (list->capcity + LISTINCREMENT)*sizeof(data));
		list->capcity += LISTINCREMENT;
	}
	textpos = list->pos++;	
	list->array[textpos] = element;
	return 1;
}

data ListDelete(struct Array_List* list,int index)
{
	if(index < 1 || index > (list->pos))
	{
		exit(0);
	}
	int p = Get_logic_index(index);
	data R_data = list->array[p];
	for(i=p;i<list->pos-1;i++)
	{
		list->array[i] = list->array[i+1];
	}
	list->pos--;
	return R_data;
}	

void access(data element)
{
	printf("%d,",(int)element);
}

void ListTravers(struct Array_List* list)
{
	for(i=0;i<list->pos;i++)
	{
		access(list->array[i]);
	}
	printf("\n");
}

#endif
