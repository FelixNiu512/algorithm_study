//
//  Stack.m
//  Stack
//
//  Created by Cody on 2021/7/14.
//

#import "Stack.h"

@interface Stack ()

@property (nonatomic, strong) NSMutableArray *list;

@end

@implementation Stack

- (instancetype)init
{
    if (self = [super init]) {
        self.list = [[NSMutableArray alloc] init];
    }
    return self;
}

/// 元素的数量
- (NSUInteger)size
{
    return _list.count;
}

/// 是否为空
- (BOOL)isEmpty
{
    return _list.count == 0;
}

/// 入栈
- (void)push:(id)element
{
    if (element) {
        [_list addObject:element];
    }
}

/// 出栈
- (id)pop
{
    if (_list.count > 0) {
        id lastObj = _list.lastObject;
        [_list removeLastObject];
        return lastObj;
    }
    return nil;
}

/// 获取栈顶元素
- (id)top
{
    if (_list.count > 0) {
        return _list.lastObject;
    }
    return nil;
}

/// 清空
- (void)clear
{
    [_list removeAllObjects];
}

@end
