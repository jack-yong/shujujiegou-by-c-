#include "bintree.h"

struct bintree* InitBinTree()
{
	struct bintree* b = (struct bintree*)malloc(sizeof(struct bintree));
	b->root = (struct tree_node*)malloc(sizeof(struct tree_node));
	b->root->data = 0;
	b->root->leftchild = NULL;
	b->root->rightchild = NULL;
	b->root->parent = NULL;
	return b;
}

struct tree_node* Creat_tree_node(element e1)
{
	struct tree_node* t1 = (struct tree_node*)malloc(sizeof(struct tree_node));
	t1->leftchild = NULL;
	t1->parent = NULL;
	t1->rightchild  = NULL;
	t1->data = e1;
	return t1;
}

void DestoryBinTree(struct bintree* b1)
{
	if(b1->root == NULL)
	{
		free(b1);
	}
	DestoryAllNode(b1->root);
	free(b1);
}

static void DestoryAllNode(struct tree_node* t1)
{
	if(t1 == NULL) return;
	DestoryAllNode(t1->leftchild);
	DestoryAllNode(t1->rightchild);
	free(t1);
}

/*void CreateBinTree(struct bintree* b1,element* e1,int length)
{
	CreateNode(b1->root,e1,length);
}

void CreatethreeNode(struct tree_node* t1,element* e1,int length)
{
	for(i)
	{
		t1->leftchild = Creat_tree_node()
	}
}*/ 

void ClearBinTree(struct bintree* b1)
{
	if(b1->root == NULL) return;
	DestoryAllNode(b1->root);
}

int BinTreeEmpty(struct bintree* b1)
{
	if(b1->root == NULL) return 1;
	return 0;
}

int BinTreeDepth(struct bintree* b1)
{
	return RootDepth(b1->root);
}

int RootDepth(struct tree_node* t1)
{
	if(t1 == NULL) return 0;
	int LeftChildDepth = RootDepth(t1->leftchild);
	int RightChildDepth  = RootDepth(t1->rightchild);
	return max(LeftChildDepth,RightChildDepth)+1;
}

struct tree_node* Root(struct bintree* b1)
{
	return b1->root;
}

/*element value(struct bintree* b1,struct tree_node* t1)
{
	
}*/

void Assign(struct bintree* b1,struct tree_node* t1,element e1)
{
	TheTravers(b1->root,t1,e1);
}

static void TheTravers(struct tree_node* t1,struct tree_node* t2,element e1)
{
	if(t1 == NULL) return;
	if(t1 == t2) t1->data = e1;
	TheTravers(t1->leftchild,t2,e1);
	TheTravers(t1->rightchild,t2,e1);
}

struct tree_node* Parent(struct tree_node* t1)
{
	return t1->parent;
}

struct tree_node* LeftChild(struct tree_node* t1)
{
	return t1->leftchild;
}

struct tree_node* RightChild(struct tree_node* t1)
{
	return t1->rightchild;
}

struct tree_node* LeftSibling(struct tree_node* t1)
{
	if(t1->parent == NULL) return NULL;
	if(t1 == t1->parent->leftchild || t1->parent->leftchild == NULL) return NULL;
	return t1->parent->leftchild;
}

struct tree_node* RightSibling(struct tree_node* t1)
{
	if(t1->parent == NULL) return NULL;
	if(t1 == t1->parent->rightchild || t1->parent->rightchild == NULL) return NULL;
	return t1->parent->rightchild;
}

void InsertRoot(struct bintree* b1,struct tree_node* t1)
{
	b1->root = t1;
}

void InsertChild(struct tree_node* t1,int flag,struct tree_node* t2)
{
	struct tree_node* Newnode ;
	if(flag == 0)
	{
		if(t1->leftchild == NULL)
		{
			t1->leftchild = t2;
			t2->parent = t1;
		}
		else return NULL;	
	}
	if(flag == 1)
	{
		if(t1->rightchild == NULL)
		{
			t1->rightchild = t2;
			t2->parent = t1;
		}
		else return NULL;
	}
}

void DeleteChild(struct tree_node* t1,int flag)
{
	if(flag == 0) DestoryAllNode(t1->leftchild);
	if(flag == 1) DestoryAllNode(t1->rightchild);
}

static void Visit(element e1)
{
	if(e1 == NULL) printf("*");
	printf("%c ",e1);
}

void PreOrderTraverse(struct bintree* b1)
{
	PreOrderNodeTraverse(b1->root);
}

static void PreOrderNodeTraverse(struct tree_node* t1)
{
	if(t1 == NULL) return;
	Visit(t1->data);
	PreOrderNodeTraverse(t1->leftchild);
	PreOrderNodeTraverse(t1->rightchild);
}

void InOrderTraverse(struct bintree* b1)
{
	InOrderNodeTraverse(b1->root);
}

static void InOrderNodeTraverse(struct tree_node* t1)
{
	if(t1 == NULL) return;
	InOrderNodeTraverse(t1->leftchild);
	Visit(t1->data);
	InOrderNodeTraverse(t1->rightchild);
}

void PostOrderTraverse(struct bintree* b1)
{
	PostOrderNodeTraverse(b1->root);
}

static void PostOrderNodeTraverse(struct tree_node* t1)
{
	if(t1 == NULL) return;
	PostOrderNodeTraverse(t1->leftchild);
	PostOrderNodeTraverse(t1->rightchild);
	Visit(t1->data);
}

void LevelOrderTraverse(struct bintree* b1)
{
	if(BinTreeEmpty(b1)) return;
	struct Queue* Q1 = InitQueue();
	EnQueue(Q1,b1->root->data);
	LevelOrderNodeTraverse(b1->root,Q1);
	DestoryQueue(Q1);
}

static void LevelOrderNodeTraverse(struct tree_node* t1,struct Queue* Q1)
{
	if(t1 == NULL) return NULL;
	Visit(DeQueue(Q1));
	if(t1->leftchild != NULL) EnQueue(Q1,t1->leftchild->data);
	if(t1->rightchild != NULL) EnQueue(Q1,t1->rightchild->data);
	LevelOrderNodeTraverse(t1->leftchild,Q1);
	LevelOrderNodeTraverse(t1->rightchild,Q1);
}

static int max(element a,element b)
{
	if(a > b || a == b) return a;
	return b;
}

void HuffmanTree(struct bintree* b1,struct Key_Value p[],int length)
{
	sort(p,length);
	int i = 0;
	//struct Key_Value compare = p[1];
	float Vcompare = p[1].value;
	struct tree_node* remember;
	for(i;i<length;i=i+2)
	{
		if(length - i == 1)
		{
			struct tree_node* Newremember = Creat_tree_node(NULL);
			InsertChild(Newremember,0,remember);
			InsertChild(Newremember,1,Creat_tree_node(p[i].key));
			remember = Newremember;
			Vcompare = p[i].value+p[i+1].value;
			//break;
		}
		if(i == 0)
		{
			remember = Creat_tree_node(NULL);
			Vcompare = p[i].value+p[i+1].value;
			InsertChild(remember,0,Creat_tree_node(p[i].key));
			InsertChild(remember,1,Creat_tree_node(p[i+1].key));
		}
		if(Vcompare + p[i].value > p[i].value + p[i+1].value &&  length - i != 1 && i != 0)
		{
			struct tree_node* Newremember1 = Creat_tree_node(NULL);
			struct tree_node* Newremember2 = Creat_tree_node(NULL);
			Vcompare += p[i].value + p[i+1].value;
			InsertChild(Newremember1,0,Creat_tree_node(p[i].key));
			InsertChild(Newremember1,1,Creat_tree_node(p[i+1].key));
			InsertChild(Newremember2,0,remember);
			InsertChild(Newremember2,1,Newremember1);
			remember = Newremember2;
		}
		if(Vcompare + p[i].value <= p[i].value + p[i+1].value && length - i != 1 && i != 0)
		{
			struct tree_node* Newremember = Creat_tree_node(NULL);
			InsertChild(Newremember,0,remember);
			InsertChild(Newremember,1,Creat_tree_node(p[i].key));
			remember = Newremember;
			Vcompare += p[i].value;
			i--;
		}
	}
	b1->root = remember;
	Assign(b1,b1->root,'$');
}

void sort(struct Key_Value p[],int length)
{
	int i = 0,j;
	struct Key_Value swap;
	for(i;i<length;i++)
	{
		for(j = i+1;j < length;j++)
		{
			if(p[i].value> p[j].value)
			{
				swap = p[i];
				p[i] = p[j];
				p[j] = swap;
			}
		}
	}
}

void K_Vvisit(struct Key_Value p[],int length)
{
	int i=0;
	for(i;i<length;i++)
	{
		printf("%c,%f",p[i].key,p[i].value);
	}
	
}
