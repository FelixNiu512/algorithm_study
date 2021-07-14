//
//  StackDemo.m
//  AlgorithmDemo
//
//  Created by Cody on 2021/7/14.
//

#import "StackDemo.h"

@implementation StackDemo

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
    NSArray *allKeys = dict.allKeys;
    NSUInteger length = brackets.length;
    NSRange range;
    for (int i = 0; i < length; i += range.length) {
        range = [brackets rangeOfComposedCharacterSequenceAtIndex:i];
        NSString *sub = [brackets substringWithRange:range];
        if ([allKeys containsObject:sub]) {// 左括号
            [stack push:sub];
        } else {// 右括号
            if (stack.isEmpty || ![sub isEqualToString:dict[stack.pop]]) {
                return NO;
            }
        }
    }
    return stack.isEmpty;
}

@end
