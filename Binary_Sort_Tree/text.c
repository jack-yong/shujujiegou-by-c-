#include "SortTree.h"
#include<time.h>

int main(int argc, char** argv) {
    srand((unsigned) time(NULL));
    int i = 1;
//    int array[9] = {8,7,9,6,10,5,11,4,12};
//    for(int i=0;i<9;i++)
//    {
//        insert(b1,array[i]);
//    }
//    PreOrderTraverse(b1);
//    printf("\n");
//    InOrderTraverse(b1);
//    printf("%d",find(b1,1));
    while(1)
    {
        if(i>10) break;
        struct bintree* b1 = InitBinTree();
        for(int i=0;i<10;i++)
        {
               int m = rand()%10;
               insert(b1,m);
        }
        PreOrderTraverse(b1);
        printf("\n");
        InOrderTraverse(b1);
        printf("\n");
        printf("\n");
        DestoryBinTree(b1);
        i++;
    }
}

