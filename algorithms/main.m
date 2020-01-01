//
//  main.m
//  algorithms
//
//  Created by Constant Cody on 12/30/19.
//  Copyright © 2019 Constant Cody. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SortNumber.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        int num[] = {6, 3, 4, 2, 9, 5, 8, 1, 7};
//        bubbleSort(num, 9);
//        selectSort(num, 9);
//        insertSort(num, 9);
//        shellSort(num, 9);
//        quickSort(num, 0, 9);
        heapsortSelf(num, 9);
        printArray(num, 9);
    }
    return 0;
}
