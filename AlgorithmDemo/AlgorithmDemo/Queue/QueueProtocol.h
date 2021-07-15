//
//  QueueProtocol.h
//  AlgorithmDemo
//
//  Created by Cody on 2021/7/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol QueueProtocol <NSObject>

@required

/// 元素的数量
- (NSUInteger)size;

/// 是否为空
- (BOOL)isEmpty;

/// 入队
- (void)enqueue:(id)element;

/// 出队
- (id)dequeue;

/// 获取队列的头元素
- (id)front;

/// 清空
- (void)clear;

@end

NS_ASSUME_NONNULL_END
