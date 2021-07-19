//
//  QueueDemo.m
//  AlgorithmDemo
//
//  Created by Cody on 2021/7/15.
//

#import "QueueDemo.h"
#import "Queue.h"
#import "Deque.h"
#import "QueueByStack.h"

@implementation QueueDemo

/// 测试队列
+ (void)testQueue
{
    Queue *queue = [[Queue alloc] init];
    [queue enqueue:@11];
    [queue enqueue:@22];
    [queue enqueue:@33];
    [queue enqueue:@44];
    while (![queue isEmpty]) {
        NSLog(@"dequeue item: %@", [queue dequeue]);
    }
}

/// 测试双端队列
+ (void)testDeque
{
    Deque *queue = [[Deque alloc] init];
    [queue enqueueFront:@11];
    [queue enqueueFront:@22];
    [queue enqueueFront:@33];   // 尾[11, 22, 33]头
    [queue enqueueRear:@44];
    [queue enqueueRear:@55];
    [queue enqueueRear:@66];    // 尾[66, 55, 44, 11, 22, 33]头
    [queue dequeueFront];       // 尾[66, 55, 44, 11, 22]头
    [queue dequeueRear];        // 尾[55, 44, 11, 22]头
    while (![queue isEmpty]) {
        NSLog(@"dequeue item: %@", [queue dequeueFront]);
    }
}

/**
 用栈实现队列：leetcode_232（https://leetcode-cn.com/problems/implement-queue-using-stacks/）
 */
+ (void)testQueueByStack
{
    QueueByStack *queue = [[QueueByStack alloc] init];
    [queue enqueue:@11];
    [queue enqueue:@22];
    [queue enqueue:@33];
    [queue enqueue:@44];
    while (![queue isEmpty]) {
        NSLog(@"dequeue item: %@", [queue dequeue]);
    }
}

@end
