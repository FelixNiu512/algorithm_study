//
//  main.m
//  algorithms
//
//  Created by Constant Cody on 12/30/19.
//  Copyright © 2019 Constant Cody. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BinarySearch.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        int array[10];
        for (int i = 0; i < 10; i++) {
            array[i] = 100 + i;
            printf("%d ", array[i]);
        }
        printf("\n109 的位置是 %d\n", binarySearch(array, 20, 109));
    }
    return 0;
}
