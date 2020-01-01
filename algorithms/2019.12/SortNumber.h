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
void sort1(int array[], int size) {
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
void sort2(int array[], int size) {
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
    插入排序
    时间复杂度：平均o(n²)，最好是o(n)
 */
void sort3(int array[], int size) {
    for (int i = 1; i < size; i++) if (array[i] < array[i-1]) {
        int temp = array[i];
        int j = i;
        while (j > 0) {
            if (temp < array[j-1]) {
                array[j] = array[j-1];
                j--;
            }
            else break;
        }
        array[j] = temp;
    }
}

/**
    快速排序：1. 取一个数作为基准数 2. 分区：将比这个数大的放右边，小的放左边 3. 重复1、2，直到各区间只有一个数
    时间复杂度：平均o(nlogn)，最差o(n²)
 */
void sort4(int array[], int left, int right) {
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
    sort4(array, left, ll-1);
    // 递归key右边区
    sort4(array, ll+1, right);
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
