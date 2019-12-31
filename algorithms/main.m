//
//  main.m
//  algorithms
//
//  Created by Constant Cody on 12/30/19.
//  Copyright © 2019 Constant Cody. All rights reserved.
//

#import <Foundation/Foundation.h>

#include "GreaterCommonDivisor.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSLog(@"gcd(24, 20) is %i", gcd3(24, 20));
        NSLog(@"lcm(24, 20) is %i", 24*20/gcd3(24, 20));
    }
    return 0;
}
