//
//  QueueDemo.h
//  AlgorithmDemo
//
//  Created by Cody on 2021/7/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface QueueDemo : NSObject

/// 测试队列
+ (void)testQueue;

/// 测试双端队列
+ (void)testDeque;

/**
 用栈实现队列：leetcode_232（https://leetcode-cn.com/problems/implement-queue-using-stacks/）
 */
+ (void)testQueueByStack;

@end

NS_ASSUME_NONNULL_END
