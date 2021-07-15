//
//  LinkedListProtocol.h
//  AlgorithmDemo
//
//  Created by Cody on 2021/7/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol LinkedListProtocol <NSObject>

@required

/// 元素的数量
- (NSUInteger)size;

/// 是否为空
- (BOOL)isEmpty;

/// 是否包含
- (BOOL)contains:(id)element;

/// 添加元素到尾部
- (void)add:(id)element;

/// 添加元素到指定位置
- (void)add:(id)element atIndex:(NSInteger)index;

/// 设置index位置的元素
- (id)set:(id)element atIndex:(NSInteger)index;

/// 获取index位置的元素
- (id)get:(NSInteger)index;

/// 查看元素的索引
- (NSInteger)indexOf:(id)element;

/// 删除index位置的元素
- (id)remove:(NSInteger)index;

/// 删除某元素
- (BOOL)removeElement:(id)element;

/// 清空所有元素
- (void)clear;

@end

NS_ASSUME_NONNULL_END
