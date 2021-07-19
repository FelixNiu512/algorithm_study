//
//  StackDemo.m
//  AlgorithmDemo
//
//  Created by Cody on 2021/7/14.
//

#import "StackDemo.h"
#import "Stack.h"
#import "StackByQueue.h"
#import "StackByQueue2.h"

@implementation StackDemo

/// 测试：有效的符号
+ (void)testIsValidBrackets
{
    NSArray<NSString *> *expArray = @[@"()[]{}", @"([)]", @"{[]}", @"{[])}"];
    for (NSString *exp in expArray) {
        NSLog(@"%@ isValid: %@", exp, [StackDemo isValidBrackets:exp] ? @"true" : @"false");
    }
}

/**
 有效的括号：leetcode_20（https://leetcode-cn.com/problems/valid-parentheses/）
 */
+ (BOOL)isValidBrackets:(NSString *)brackets
{
    if (!brackets || !brackets.length) {
        return NO;
    }
    Stack *stack = [[Stack alloc] init];
    NSDictionary<NSString *, NSString *> *dict = @{
        @"(" : @")",
        @"[" : @"]",
        @"{" : @"}",
    };
    NSUInteger length = brackets.length;
    NSRange range;
    for (int i = 0; i < length; i += range.length) {
        range = [brackets rangeOfComposedCharacterSequenceAtIndex:i];
        NSString *sub = [brackets substringWithRange:range];
        if ([dict.allKeys containsObject:sub]) {// 左括号
            [stack push:sub];
        } else {// 右括号
            if (stack.isEmpty || ![sub isEqualToString:dict[stack.pop]]) {
                return NO;
            }
        }
    }
    return stack.isEmpty;
}

/**
 用队列实现栈：leetcode_225（https://leetcode-cn.com/problems/implement-stack-using-queues/）
 */
+ (void)testStackByQueue
{
    StackByQueue2 *stack = [[StackByQueue2 alloc] init];
    [stack push:@11];
    [stack push:@22];
    [stack push:@33];
    [stack push:@44];
    
    while (![stack isEmpty]) {
        NSLog(@"pop item: %lld", ((NSNumber *)[stack pop]).longLongValue);
    }
}

@end
