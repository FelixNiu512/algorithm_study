//
//  BinarySearch.h
//  algorithms
//
//  Created by Constant Cody on 1/2/20.
//  Copyright © 2020 Constant Cody. All rights reserved.
//

#ifndef BinarySearch_h
#define BinarySearch_h

/**
    要求：1. 数组必须是有序的
 */
int binarySearch(int array[], int size, int key) {
    int min = 0, max = size - 1;
    int mid;
    while (min <= max) {
        mid = (min + max) / 2;
        if (key == array[mid]) {
            return mid;
        }
        if (key > array[mid]) {
            min = mid + 1;
        }
        else {
            max = mid - 1;
        }
    }
    return -1;
}

#endif /* BinarySearch_h */
