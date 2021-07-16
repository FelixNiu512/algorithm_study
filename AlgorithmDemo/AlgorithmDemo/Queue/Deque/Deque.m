//
//  Deque.m
//  AlgorithmDemo
//
//  Created by Cody on 2021/7/16.
//

#import "Deque.h"
#import "DoublyLinkedList.h"

@interface Deque ()

@property (nonatomic, strong) DoublyLinkedList *list;

@end

@implementation Deque

- (instancetype)init
{
    if (self = [super init]) {
        self.list = [[DoublyLinkedList alloc] init];
    }
    return self;
}

#pragma mark - DequeProtocol

/// 元素的数量
- (NSUInteger)size
{
    return [_list size];
}

/// 是否为空
- (BOOL)isEmpty
{
    return [_list isEmpty];
}

/// 入队：默认从队尾入队
- (void)enqueue:(id)element
{
    [self enqueueRear:element];
}

/// 出队：默认从队头出队
- (id)dequeue
{
    return [self dequeueFront];
}

/// 获取队列的头元素
- (id)front
{
    return [_list get:0];
}

/// 清空
- (void)clear
{
    [_list clear];
}

/// 从队头出队
- (id)dequeueFront
{
    return [_list remove:0];
}

/// 从队尾出队
- (id)dequeueRear
{
    return [_list remove:(_list.size - 1)];
}

/// 从队头入队
- (void)enqueueFront:(id)element
{
    [_list add:element atIndex:0];
}

/// 从队尾入队
- (void)enqueueRear:(id)element
{
    [_list add:element];
}

/// 获取队尾元素
- (id)rear
{
    return [_list get:(_list.size - 1)];
}

@end
