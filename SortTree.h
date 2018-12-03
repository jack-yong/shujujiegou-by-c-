#ifndef SORTTREE_H
#define SORTTREE_H

#include <stdio.h> 

typedef int element;

struct tree_node {
    element data;
    struct tree_node* leftchild;
    struct tree_node* rightchild;
    struct tree_node* parent;
};

struct bintree {
    struct tree_node* root;
};

struct bintree* InitBinTree();
struct tree_node * Creat_Node(element elem);
void insert(struct bintree* b1, element e1);
void insert_node(struct tree_node* n1, element e1);
int find(struct bintree* b1, element e1); //when the return value is '0',means not find;else find.
int find_node(struct tree_node* n1, element e1);
static void Visit(element e1);
void PreOrderTraverse(struct bintree* b1);
static void PreOrderNodeTraverse(struct tree_node* t1);
void InOrderTraverse(struct bintree* b1);
static void InOrderNodeTraverse(struct tree_node* t1);
static void DestoryAllNode(struct tree_node* t1);
void DestoryBinTree(struct bintree* b1);

#endif