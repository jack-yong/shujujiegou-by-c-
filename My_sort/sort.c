#include "sort.h"

void Insert_Sort(element* a, int len) {
    //    int swap;
    for (int i = 0; i < len; i++) {
        int pre_pos = i - 1;
        //        int temp = a[i];
        for (pre_pos; pre_pos >= 0; pre_pos--) {
            if (a[pre_pos] > a[pre_pos + 1]) {
                swap(a, pre_pos, pre_pos + 1);
                //                a[pre_pos] = temp;
                //                a[pre_pos + 1] = temp;
            } else break;
        }
    }
}

void swap(element* a, int cur, int pre) {
    int swap;
    swap = a[cur];
    a[cur] = a[pre];
    a[pre] = swap;
}
//pop sort

void Pop_Sort(element* a, int len) {
    //    int swap;
    for (int pos = 0; pos < len; pos++) {
        for (int min_num2pos = len - 2; min_num2pos >= pos; min_num2pos--) {
            if (a[min_num2pos + 1] < a[min_num2pos]) {
                swap(a, min_num2pos, min_num2pos + 1);
                //                swap = a[i];
                //                a[i] = a[j];
                //                a[j] = swap;
            }
        }

    }
}

void Select_Sort(element* a, int len) {
    for (int i = len - 1; i >= 0; i--) {
        int Mpos = 0;
        int swap;
        for (int j = 0; j <= i; j++) {
            if (a[j] > a[Mpos]) {
                Mpos = j;
            }
        }
        swap = a[i];
        a[i] = a[Mpos];
        a[Mpos] = swap;
    }
}

void Shell_Sort(element* a, int len, int* sep, int seplen) {
    for (int i = seplen - 1; i >= 0; i--) {
        Shell_Sort_step(a, len, sep[i]);
    }
}

void Shell_Sort_step(element* a, int len, int step) {
    for (int pos = 0; pos < step; pos++) {
        for (int step_pos = pos; step_pos < len; step_pos += step) {
            int pre_pos = step_pos - step;
            //            int temp = a[step_pos];
            for (pre_pos; pre_pos >= 0; pre_pos -= step) {
                if (a[pre_pos] > a[pre_pos + step]) {
                    swap(a, pre_pos, pre_pos + step);
                } else break;
                //                a[pre_pos] > temp &&
                //                a[pre_pos] = a[pre_pos + 1];
            }
            //            a[pre_pos + 1] = temp;
        }
    }
}

void Quick_Sort(element* a, int len) {
    if (len < 1) printf("the length of Array is too short!!!");
    Quick_Sort_DiGui(a, 1, len - 1);
}

void Quick_Sort_DiGui(element* a, int begin, int end) {
    int privot_pos = begin - 1;
    int end_pos = end;
    if (begin - end > 0) return;
    while (begin <= end) {
        if (a[begin] <= a[privot_pos]) begin++;
        else if (a[end] >= a[privot_pos]) end--;
        else swap(a, begin, end);
    }
    swap(a, privot_pos, end);
    Quick_Sort_DiGui(a, privot_pos + 1, end - 1);
    Quick_Sort_DiGui(a, begin + 1, end_pos);

}

void Head_sort(element* a, int len) {
    //建堆
    for (int i = len / 2; i >= 1; i--) {
        select(a, i, len);
    }

    //筛选数据
    for (int end = len; end >= 1; end--) {
        select(a, 1, end);
        //        Show_Array(a, Len2Array);
        swap(a, 0, end - 1);
        //        Show_Array(a, Len2Array);
    }
}

static void select(element* a, int start, int end) {
    int start_pos = start;
    while (2 * start_pos <= end) {
        int max = 2 * start_pos;
        if (max + 1 <= end && a[max] > a[max - 1]) {
            max++;
        }
        if (a[max - 1] <= a[start_pos - 1]) {
            break;
        }
        swap(a, start_pos - 1, max - 1);
        start_pos = max; //已经建立了一棵完全二叉树，只会引起下边子书一边的变化
    }
}

void Merging_Sort(element* a, int len) {
    Merging_Sort_DiGui(a, 0, len - 1);
}

static void Merging_Sort_DiGui(element* a, int start, int end) {
    if (start == end) return;
    int min = (start + end) / 2;
    Merging_Sort_DiGui(a, start, min);
    Merging_Sort_DiGui(a, min + 1, end);
    Merging_Base_Sort(a, start, min, min + 1, end);
}

static void Merging_Base_Sort(element* a, int start1, int end1, int start2, int end2) {
    int length = (end1 - start1 + 1)+(end2 - start2 + 1);
    if (length == 0) return;
    int sp1 = start1, sp2 = start2;
    element* p = (element*) malloc(sizeof (element) * length);
    int pos = 0;
    while (sp1 <= end1 && sp2 <= end2) {
        if (a[sp1] < a[sp2]) {
            p[pos++] = a[sp1++];
        } else {
            p[pos++] = a[sp2++];
        }
    }
    if (sp1 > end1) {
        while (sp2 <= end2) {
            p[pos++] = a[sp2++];
        }
    } else {
        while (sp1 <= end1) {
            p[pos++] = a[sp1++];
        }
    }
    sp1 = start1, sp2 = start2, pos = 0;
    for (int k = sp1; k <= end1; k++) {
        a[sp1++] = p[pos++];
    }
    for (int q = sp2; q <= end2; q++) {
        a[sp2++] = p[pos++];
    }
    free(p);
}

void Base_number_sort(element* a, int len) {
    struct Queue * q[10];
    int flag = max_number(a,len);
    for (int i = 0; i < 10; i++) {
        q[i] = InitQueue();
    }
    for (int k = 0;k<flag; k++) {
        //        printf("%d",length(q[0]));
        for (int j = 0; j < len; j++) {
            int p = (int)(a[j] /  pow(10, k)) % 10;// int强制转换应该放在表达式外侧
//            printf("%d,%d\n",a[j] ,(int)(a[j] /  pow(10, k)) % 10);
            EnQueue(q[p], a[j]);
        }
        int pos = 0;
//        int Queue_length = length(q[0]);
        for (int i = 0; i < 10; i++) {
            while (!isEmpty(q[i])) {
                a[pos++] = DeQueue(q[i]);
            }
        }
        //        if (Queue_length == len && k != 0) break;
    }
    for (int i = 0; i < 10; i++) {
        DestoryQueue(q[i]);
    }
}

static int max_number(element* a, int len) {
    int max = a[0];
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] > max) max = a[i];
    }
    while (max != 0) {
        max /= 10;
        count++;
    }
    return count;
}

void check(element* a, int len) {
    int flag = 0;
    //    printf("%d",a[0]);
    for (int i = 0; i < len - 1; i++) {
        if (a[i] > a[i + 1]) {
            flag = 1;
            break;
        }
        //        printf("%d ", a[i]);
    }

    //    printf("\n");
    if (flag == 1) printf("Error!!!\n");
    else printf("Right!!!\n");
}

element* Init_Array() {
    element* p = (element*) malloc(sizeof (element) * Len2Array);
    for (int i = 0; i < Len2Array; i++) {
        int m = (rand() % mo) + 1;
        p[i] = m;
    }
    return p;
}

void Show_Array(element* a, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int* CreatZLYZ(int len) {
    int* p = (int*) malloc(sizeof (int) * len);
    p[0] = 1;
    for (int i = 1; i < len; i++) {
        p[i] = (int) (pow(4, i) + 3 * pow(2, i - 1) + 1);
    }
    return p;
}


