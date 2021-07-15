//
//  Queue.m
//  AlgorithmDemo
//
//  Created by Cody on 2021/7/14.
//

#import "Queue.h"
#import "DoublyLinkedList.h"

@interface Queue ()

@property (nonatomic, strong) DoublyLinkedList *list;

@end

@implementation Queue

- (instancetype)init
{
    if (self = [super init]) {
        self.list = [[DoublyLinkedList alloc] init];
    }
    return self;
}

#pragma mark - QueueProtocol

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

/// 入队
- (void)enqueue:(id)element
{
    [_list add:element];
}

/// 出队
- (id)dequeue
{
    return [_list remove:0];
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

@end
