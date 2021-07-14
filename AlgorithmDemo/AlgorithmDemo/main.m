//
//  main.m
//  AlgorithmDemo
//
//  Created by Cody on 2021/7/14.
//

#import <Foundation/Foundation.h>
#import "Stack.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        Stack *stack = [[Stack alloc] init];
        [stack push:@(11)];
        [stack push:@(22)];
        [stack push:@(33)];
        [stack push:@(44)];
        
        while (![stack isEmpty]) {
            NSLog(@"pop item: %lld", ((NSNumber *)[stack pop]).longLongValue);
        }
    }
    return 0;
}
