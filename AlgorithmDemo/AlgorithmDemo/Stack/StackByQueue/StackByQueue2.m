//
//  StackByQueue2.m
//  AlgorithmDemo
//
//  Created by Cody on 2021/7/19.
//

#import "StackByQueue2.h"
#import "Queue.h"

@implementation StackByQueue2
{
    Queue *_queue;
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        _queue = [[Queue alloc] init];
    }
    return self;
}

#pragma mark - StackProtocol

- (void)clear
{
    [_queue clear];
}

- (BOOL)isEmpty
{
    return [_queue isEmpty];
}

/// 出栈
- (id)pop
{
    return [_queue dequeue];
}

/// 入栈
- (void)push:(id)element
{
    NSUInteger preSize = [_queue size];
    [_queue enqueue:element];
    for (NSUInteger i = 0; i < preSize; i++) {
        id element = [_queue dequeue];
        [_queue enqueue:element];
    }
}

- (NSUInteger)size
{
    return [_queue size];
}

/// 获取栈顶元素
- (id)top
{
    return [_queue front];
}
@end
