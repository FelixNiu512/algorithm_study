//
//  SwapNumber.h
//  algorithms
//
//  Created by Constant Cody on 12/30/19.
//  Copyright © 2019 Constant Cody. All rights reserved.
//

#ifndef SwapNumber_h
#define SwapNumber_h

#include <stdio.h>

/**
    交换：用中间变量
 */
void swap1(int a, int b) {
    int t = a;
    a = b;
    b = t;
    NSLog(@"result: a = %i, b = %i", a, b);
}

/**
    交换：加法，无中间变量
 */
void swap2(int a, int b) {
    a = a + b;
    b = a - b;
    a = a - b;
    NSLog(@"result: a = %i, b = %i", a, b);
}

/**
    交换：异或，无中间变量
 */
void swap3(int a, int b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    NSLog(@"result: a = %i, b = %i", a, b);
}

#endif /* SwapNumber_h */
