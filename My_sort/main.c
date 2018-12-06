#include "sort.h"
static int V = 10000;
#define step_Array_length 3 //这个数字不应过大，最好在小于10
//static int len = 20;

int main(int argc, char** argv) {

    int i = 0;
    srand((unsigned) time(NULL));
    while (1) {
        if (i > V) break;
        //        element Array[4] = {91, 38, 100, 99};
        element* Array = Init_Array();
        //        int* step_Array = CreatZLYZ(step_Array_length);
        //        Show_Array(Array, Len2Array);
        //        printf("%d", Len2Array);
        //        Insert_Sort(Array, Len2Array);    //插入排序
        //        Pop_Sort(Array, Len2Array);       //冒泡排序
        //        Select_Sort(Array, Len2Array);    //选择排序
        //        Shell_Sort(Array, Len2Array, step_Array, step_Array_length); //步长排序，需要配合step_Array使用，且需要释放。
        //        Quick_Sort(Array, Len2Array); //  快速排序
        //        Head_sort(Array, Len2Array);  //堆排序
        //        Merging_Sort(Array, Len2Array); //归并排序
        //        Base_number_sort(Array, Len2Array); // 基数排序
        //        Show_Array(Array, Len2Array);
        check(Array, Len2Array);
        free(Array);
        //        free(step_Array);
        i++;
    }

}

