//
//  QueueByStack.m
//  AlgorithmDemo
//
//  Created by Cody on 2021/7/19.
//

#import "QueueByStack.h"
#import "Stack.h"

@implementation QueueByStack
{
    Stack *_inStack;
    Stack *_outStack;
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        _inStack = [[Stack alloc] init];
        _outStack = [[Stack alloc] init];
    }
    return self;
}

#pragma mark - QueueProtocol

/// 清空元素
- (void)clear
{
    [_inStack clear];
    [_outStack clear];
}

/// 出队
- (id)dequeue
{
    [self checkOutStack];
    return [_outStack pop];
}

/// 入队
- (void)enqueue:(id)element
{
    [_inStack push:element];
}

/// 获取队头
- (id)front
{
    [self checkOutStack];
    return [_outStack top];
}

/// 是否为空
- (BOOL)isEmpty
{
    return [_inStack isEmpty] && [_outStack isEmpty];
}

- (NSUInteger)size
{
    return [_inStack size] + [_outStack size];
}

#pragma mark - Private

/// 如果outStack为空，把inStack中的数据倾倒到outStack中
- (void)checkOutStack
{
    if ([_outStack isEmpty]) {
        while (![_inStack isEmpty]) {
            [_outStack push:[_inStack pop]];
        }
    }
}

@end
