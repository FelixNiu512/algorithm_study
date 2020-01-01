//
//  SortNumber.h
//  algorithms
//
//  Created by Constant Cody on 12/31/19.
//  Copyright © 2019 Constant Cody. All rights reserved.
//

#ifndef SortNumber_h
#define SortNumber_h

#include <stdio.h>

void swap(int *, int *);

/**
    冒泡排序
    时间复杂度：o(n²)
 */
void bubbleSort(int array[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

/**
    选择排序：标记下标
    时间复杂度：o(n²)，实际优于冒泡，因为交换次数少
 */
void selectSort(int array[], int size) {
    int min;
    for (int i = 0; i < size; i++) {
        min = i;
        for (int j = i+1; j < size; j++) {
            if (array[min] > array[j]) {
                min = j;
            }
        }
        if (min != i) {
            swap(&array[i], &array[min]);
        }
    }
}

/**
    直接插入排序：将一个数据插入到一组已经排好序的序列当中，插入后该序列依旧是有序的
    时间复杂度：平均o(n²)，最好是o(n)
 */
void insertSort(int array[], int size) {
    for (int i = 1; i < size; i++) if (array[i] < array[i-1]) {
        int temp = array[i];
        int j = i;
        while (j > 0 && array[j-1] > temp) {
            array[j] = array[j-1];
            j--;
        }
        array[j] = temp;
    }
}

/**
    希尔排序：是直接插入排序的升级版本，又称为“缩小增量排序”，其主要思想是把记录按下标的一定增量分组，对每组使用直接插入排序算法排序；随着增量逐渐减少，每组包含的关键词越来越多，当增量减至1时，整个文件恰被分成一组
    时间复杂度：o(n^(1.3-2))
 */
void shellSort(int array[], int size) {
    for (int gap = size/2; gap >= 1; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = array[i];
            int j = i-gap;
            while (j >= 0 && array[j] > temp) {
                array[j+gap] = array[j];
                j -= gap;
            }
            array[j+gap] = temp;
        }
    }
}

/**
    快速排序：通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，
            然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。
    步骤：1. 取一个数作为基准数 2. 分区：将比这个数大的放右边，小的放左边 3. 重复1、2，直到各区间只有一个数
    时间复杂度：平均o(nlogn)，最差o(n²)
 */
void quickSort(int array[], int left, int right) {
    if (left >= right) {
        return ;
    }
    int ll = left;
    int rr = right;
    int key = array[left];
    while (ll < rr) {
        // 右->左开始遍历找，直到找到第一个小于key的数为止
        while (ll < rr && array[rr] >= key) {
            rr--;
        }
        array[ll] = array[rr];
        // 左->右开始遍历找，直到找到第一个大于key的数为止
        while (ll < rr && array[ll] <= key) {
            ll++;
        }
        array[rr] = array[ll];
    }
    // 此时ll与rr相等
    array[ll] = key;
    
    // 递归key左边区
    quickSort(array, left, ll-1);
    // 递归key右边区
    quickSort(array, ll+1, right);
}

void maxHeapify(int array[], int start, int end) {
    // 建立父节点index和子节点index
    int dad = start;
    int son = dad*2 + 1;
    while (son <= end) { // 若子节点index在范围内才做比较
        if (son+1 <= end && array[son] < array[son+1]) // 先比较两个子节点大小，选择最大的
            son++;
        if (array[dad] > array[son]) // 如果父节点值大于子节点值说明调整完毕，直接跳出函数
            return;
        else { // 否则交换父子内容再继续子节点和孙节点比较
            swap(&array[dad], &array[son]);
            dad = son;
            son = dad*2 + 1;
        }
    }
}

/**
    堆排序：
    时间复杂度：o(nlogn)
 */
void heapsortSelf(int array[], int size) {
    int i;
    // 初始化，i从最後一个父节点开始调整
    for (i = size/2 - 1; i >= 0; i--) {
        maxHeapify(array, i, size-1);
    }
    // 先将第一个元素和已排好元素前一位做交换，再重新调整，直到排序完毕
    for (i = size-1; i > 0; i--) {
        swap(&array[0], &array[i]);
        maxHeapify(array, 0, i-1);
    }
}

/**
   交换
*/
void swap(int *a, int *b)  {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

/**
    打印
 */
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");
}

#endif /* SortNumber_h */
