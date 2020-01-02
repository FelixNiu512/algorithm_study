//
//  StackSimulator.h
//  algorithms
//
//  Created by Constant Cody on 1/2/20.
//  Copyright © 2020 Constant Cody. All rights reserved.
//

#ifndef StackSimulator_h
#define StackSimulator_h

static int data[1024];
static int count = 0;

bool full(void);
bool empty(void);

/**
    压栈
 */
void push(int a) {
    assert(!full());
    data[count++] = a;
}
/**
    出栈
 */
int pop() {
    assert(!empty());
    return data[--count];
}
/**
    返回栈顶元素
 */
int top() {
    assert(!empty());
    return data[count-1];
}

bool full() {
    return count >= 1024;
}

bool empty() {
    return count <= 0;
}

#endif /* StackSimulator_h */
