//
//  StackDemo.h
//  AlgorithmDemo
//
//  Created by Cody on 2021/7/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface StackDemo : NSObject

#pragma mark - Test Methods

/// 测试：有效的符号
+ (void)testIsValidBrackets;

#pragma mark - LeetCode

/**
 有效的括号：leetcode_20（https://leetcode-cn.com/problems/valid-parentheses/）
 */
+ (BOOL)isValidBrackets:(NSString *)brackets;

/**
 用队列实现栈：leetcode_225（https://leetcode-cn.com/problems/implement-stack-using-queues/）
 */
+ (void)testStackByQueue;

@end

NS_ASSUME_NONNULL_END
