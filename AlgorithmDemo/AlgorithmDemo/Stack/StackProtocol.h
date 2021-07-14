//
//  StackProtocol.h
//  Stack
//
//  Created by Cody on 2021/7/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol StackProtocol <NSObject>

@required

/// 元素的数量
- (NSUInteger)size;

/// 是否为空
- (BOOL)isEmpty;

/// 入栈
- (void)push:(id)element;

/// 出栈
- (id)pop;

/// 获取栈顶元素
- (id)top;

@optional

/// 清空
- (void)clear;

@end

NS_ASSUME_NONNULL_END
