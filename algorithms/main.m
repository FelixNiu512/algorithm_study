//
//  main.m
//  algorithms
//
//  Created by Constant Cody on 12/30/19.
//  Copyright © 2019 Constant Cody. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "StackSimulator.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // 入栈
        for (int i = 10; i <= 20; i++) {
            push(i);
        }
        
        // 出栈
        while (!empty()) {
            printf("%d ", top());
            pop();
        }
        printf("\n");
    }
    return 0;
}
