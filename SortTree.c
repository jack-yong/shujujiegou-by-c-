#include "SortTree.h"

struct bintree* InitBinTree() {
    struct bintree* b1 = (struct bintree*) malloc(sizeof (struct bintree));
    b1->root = (struct tree_node*) malloc(sizeof (struct tree_node));
    b1->root->data = NULL;
    b1->root->leftchild = NULL;
    b1->root->rightchild = NULL;
    b1->root->parent = NULL;
    return b1;
}

struct tree_node * Creat_Node(element elem) {
    struct tree_node* N_node = (struct tree_node *) malloc(sizeof (struct tree_node));
    if (N_node == NULL) {
        return NULL;
    }
    N_node->data = elem;
    N_node->parent = NULL;
    N_node->leftchild = NULL;
    N_node->rightchild = NULL;
    return N_node;
}

void insert(struct bintree* b1, element e1) {

    if (b1->root->data == NULL) {
        struct tree_node * Node1 = Creat_Node(e1);
        b1->root = Node1;
    } else {
        insert_node(b1->root, e1);
    }
}

void insert_node(struct tree_node* n1, element e1) {
    if (n1->data > e1) {
        if (n1->leftchild == NULL) {
            struct tree_node * Node1 = Creat_Node(e1);
            n1->leftchild = Node1;
            Node1->parent = n1;
        } else {
            insert_node(n1->leftchild, e1);
        }
    } else {
        if (n1->rightchild == NULL) {
            struct tree_node * Node2 = Creat_Node(e1);
            n1->rightchild = Node2;
            Node2->parent = n1;
        } else {
            insert_node(n1->rightchild, e1);
        }
    }
}

int find(struct bintree* b1, element e1) {
    if (b1->root == NULL) return 0;
    return find_node(b1->root, e1);
}

int find_node(struct tree_node* n1, element e1) {
    if (n1->data == e1) return 1;
    if (n1->data > e1) {
        if (n1->leftchild == NULL) return 0;
        else {
            return find_node(n1->leftchild, e1);
        }
    }
    if (n1->data < e1) {
        if (n1->rightchild == NULL) return 0;
        else {
            return find_node(n1->rightchild, e1);
        }
    }


}

static void Visit(element e1) {
    //if (e1 == NULL) printf("*");
    printf("%d ", e1);
}

void PreOrderTraverse(struct bintree* b1) {
    PreOrderNodeTraverse(b1->root);
}

static void PreOrderNodeTraverse(struct tree_node* t1) {
    if (t1 == NULL) return;
    Visit(t1->data);
    PreOrderNodeTraverse(t1->leftchild);
    PreOrderNodeTraverse(t1->rightchild);
}

void InOrderTraverse(struct bintree* b1) {
    InOrderNodeTraverse(b1->root);
}

static void InOrderNodeTraverse(struct tree_node* t1) {
    if (t1 == NULL) return;
    InOrderNodeTraverse(t1->leftchild);
    Visit(t1->data);
    InOrderNodeTraverse(t1->rightchild);
}

static void DestoryAllNode(struct tree_node* t1) {
    if (t1 == NULL) return;
    DestoryAllNode(t1->leftchild);
    DestoryAllNode(t1->rightchild);
    free(t1);
}

void DestoryBinTree(struct bintree* b1) {
    if (b1->root == NULL) {
        free(b1);
    }
    DestoryAllNode(b1->root);
    free(b1);
}