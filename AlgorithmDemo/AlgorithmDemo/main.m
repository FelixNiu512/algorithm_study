//
//  main.m
//  AlgorithmDemo
//
//  Created by Cody on 2021/7/14.
//

#import <Foundation/Foundation.h>
#import "StackDemo.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        NSArray<NSString *> *expArray = @[@"()[]{}", @"([)]", @"{[]}", @"{[])}"];
        for (NSString *exp in expArray) {
            NSLog(@"%@ isValid: %@", exp, [StackDemo isValidBrackets:exp] ? @"true" : @"false");
        }
    }
    return 0;
}
