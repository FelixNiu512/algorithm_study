//
//  QueueDemo.m
//  AlgorithmDemo
//
//  Created by Cody on 2021/7/15.
//

#import "QueueDemo.h"
#import "Queue.h"

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

@end
