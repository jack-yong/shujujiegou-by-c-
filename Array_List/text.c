#include "Arraylist.h"
#define size 10

void Union(struct Array_List* L1,struct Array_List* L2)
{
	int L1_length = Length(L1), L2_length = Length(L2),i = 1;
	for(i;i <= L1_length;i++)
	{
		if(!Find(L2,GetElem(L1,i)))
			Append_List(L2,GetElem(L1,i));
	}
	
}
int main()
{
	/*
		下方下划线的代码为验证顺序表的程序，基本验证了顺序表中的所有功能函数，
	/******************************************************************
	int i=0;
	struct Array_List* M_list = init(size);
	for(i=0;i<size;i++)
	{
		Listinsert(M_list,i,i+1);
	}
	ListTravers(M_list);
	printf("%d",Length(M_list));
	printf("\n");
	ListTravers(M_list);
	Destory(M_list);
	*********************请从下方开始**************************************/
	int i=0;
	struct Array_List * L1 = init(size);
	struct Array_List * L2 = init(size);
	for(i=0;i<size;i++)
	{
		Listinsert(L1,i,i+1);
		Listinsert(L2,i+10,i+1);
	}
	Union(L1,L2);
	ListTravers(L2);
	Destory(L1);
	Destory(L2);
}
