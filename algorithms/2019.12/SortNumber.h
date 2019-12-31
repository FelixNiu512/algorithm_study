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
    选择排序
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
    时间复杂度：平均o(n²)
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
