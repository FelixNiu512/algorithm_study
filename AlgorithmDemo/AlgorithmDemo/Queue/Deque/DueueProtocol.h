//
//  DueueProtocol.h
//  AlgorithmDemo
//
//  Created by Cody on 2021/7/16.
//

#import <Foundation/Foundation.h>
#import "QueueProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol DueueProtocol <QueueProtocol>

@required

/// 从队尾入队
- (void)enqueueRear:(id)element;

/// 从队头入队
- (void)enqueueFront:(id)element;

/// 从队尾出队
- (id)dequeueRear;

/// 从队头出队
- (id)dequeueFront;

/// 获取队尾元素
- (id)rear;

@end

NS_ASSUME_NONNULL_END
