#ifndef BINTREE_H
#define BINTREE_H

#include "queue.h" 
#include <math.h>
 
typedef char element;

struct tree_node{
	element data;
	struct tree_node* leftchild;
	struct tree_node* rightchild;
	struct tree_node* parent;
};

struct bintree{
	struct tree_node* root;
};

struct Key_Value{
	char key; //ÔªËØ 
	float value; //È¨Öµ 
};

struct bintree* InitBinTree();
struct tree_node* Creat_tree_node(element e1);
void DestoryBinTree(struct bintree* b1);
static void DestoryAllNode(struct tree_node* t1);
//void CreateBinTree(struct bintree* b1,element* e1,int length);
//void CreatethreeNode(struct tree_node* t1,element* e1,int length);
void ClearBinTree(struct bintree* b1);
int BinTreeEmpty(struct bintree* b1);
int BinTreeDepth(struct bintree* b1);
int RootDepth(struct tree_node* t1);
struct tree_node* Root(struct bintree* b1);
//element value(struct bintree* b1,struct tree_node* t1);
void Assign(struct bintree* b1,struct tree_node* t1,element e1);
static void TheTravers(struct tree_node* t1,struct tree_node* t2,element e1);
struct tree_node* Parent(struct tree_node* t1);
struct tree_node* LeftChild(struct tree_node* t1);
struct tree_node* RightChild(struct tree_node* t1);
struct tree_node* LeftSibling(struct tree_node* t1);
struct tree_node* RightSibling(struct tree_node* t1);
void InsertRoot(struct bintree* b1,struct tree_node* t1);
void InsertChild(struct tree_node* t1,int flag,struct tree_node* t2);
void DeleteChild(struct tree_node* t1,int flag);
static void Visit(element e1);
void PreOrderTraverse(struct bintree* b1);
static void PreOrderNodeTraverse(struct tree_node* t1);
void InOrderTraverse(struct bintree* b1);
static void InOrderNodeTraverse(struct tree_node* t1);
void PostOrderTraverse(struct bintree* b1);
static void PostOrderNodeTraverse(struct tree_node* t1);
void LevelOrderTraverse(struct bintree* b1);
static void LevelOrderNodeTraverse(struct tree_node* t1,struct Queue* Q1);
static int max(element a,element b);
void HuffmanTree(struct bintree* b1,struct Key_Value p[],int length);
void sort(struct Key_Value p[],int length);
void K_Vvisit(struct Key_Value p[],int length);

#endif




