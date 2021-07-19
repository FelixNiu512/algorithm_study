//
//  StackByQueue.m
//  AlgorithmDemo
//
//  Created by Cody on 2021/7/19.
//

#import "StackByQueue.h"
#import "Queue.h"

@implementation StackByQueue
{
    Queue *_queue1;
    Queue *_queue2;
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        _queue1 = [[Queue alloc] init];
        _queue2 = [[Queue alloc] init];
    }
    return self;
}

#pragma mark - StackProtocol

- (void)clear
{
    [_queue1 clear];
}

- (BOOL)isEmpty
{
    return [_queue1 isEmpty];
}

/// 出栈
- (id)pop
{
    return [_queue1 dequeue];
}

/// 入栈
- (void)push:(id)element
{
    [_queue2 enqueue:element];
    while (![_queue1 isEmpty]) {
        id element = [_queue1 dequeue];
        [_queue2 enqueue:element];
    }
    Queue *temp = _queue1;
    _queue1 = _queue2;
    _queue2 = temp;
}

- (NSUInteger)size
{
    return [_queue1 size];
}

/// 获取栈顶元素
- (id)top
{
    return [_queue1 front];
}

@end
