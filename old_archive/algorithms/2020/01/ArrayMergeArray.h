//
//  ArrayMergeArray.h
//  algorithms
//
//  Created by Constant Cody on 1/2/20.
//  Copyright © 2020 Constant Cody. All rights reserved.
//

#ifndef ArrayMergeArray_h
#define ArrayMergeArray_h

/**
    有序数组合并
 */
int* mergeArrays(int arr1[], int size1, int arr2[], int size2) {
    int i1 = 0, i2 = 0, i = 0;
    int *tArr = malloc(sizeof(size1+size2));
    while (i1 < size1 && i2 < size2) {
        tArr[i++] = arr1[i1] < arr2[i2] ? arr1[i1++] : arr2[i2++];
    }
    while (i1 < size1) {
        tArr[i++] = arr1[i1++];
    }
    while (i2 < size2) {
        tArr[i++] = arr2[i2++];
    }
    return tArr;
}

#endif /* ArrayMergeArray_h */
