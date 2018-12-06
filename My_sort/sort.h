#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "queue.h"

typedef int element;
#define Len2Array 20
#define mo 100
//static int k = 0;
element* Init_Array();
int* CreatZLYZ(int len);
void Insert_Sort(element* a, int len);
void Select_Sort(element* a, int len);
void Pop_Sort(element* a, int len);
void Shell_Sort(element* a, int len, int* sep, int seplen);
void Shell_Sort_step(element* a, int len, int step);
void Quick_Sort(element* a, int len);
void Quick_Sort_DiGui(element* a, int begin, int end) ;
void Head_sort(element* a, int len);
static void select(element* a, int start, int end);
void Merging_Sort(element* a, int len);
static void Merging_Sort_DiGui(element* a, int start, int end);
static void Merging_Base_Sort(element* a,int start1,int end1,int start2,int end2);
void Base_number_sort(element* a, int len);
static int max_number(element* a, int len);
void check(element* a, int len);
void Show_Array(element* a, int len);
void swap(element* a,int cur,int pre);

#endif
