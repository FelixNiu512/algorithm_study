//
//  main.m
//  algorithms
//
//  Created by Constant Cody on 12/30/19.
//  Copyright © 2019 Constant Cody. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ArrayMergeArray.h"

/**
    打印
 */
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        int num1[] = {1, 3, 5, 5, 7};
        int num2[] = {2, 2, 4, 6, 6, 6, 8};
        printArray(num1, 5);
        printArray(num2, 7);
        
        printArray(mergeArrays(num1, 5, num2, 7), 12);
    }
    return 0;
}
