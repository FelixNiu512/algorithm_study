//
//  DoublyLinkedList.m
//  AlgorithmDemo
//
//  Created by Cody on 2021/7/14.
//

#import "DoublyLinkedList.h"
#import "Node.h"

@interface DoublyLinkedList ()

@property (nonatomic, assign) NSUInteger size;

@end

@implementation DoublyLinkedList {
    @private
    DoublyListNode *_first;
    DoublyListNode *_last;
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        _size = 0;
        _first = NULL;
        _last = NULL;
    }
    return self;
}

#pragma mark - LinkedListProtocol

/// 元素的数量
- (NSUInteger)size
{
    return _size;
}

/// 是否为空
- (BOOL)isEmpty
{
    return _size == 0;
}

/// 是否包含
- (BOOL)contains:(id)element
{
    return [self indexOf:element] != ELEMENT_NOT_FOUND;
}

/// 添加元素到尾部
- (void)add:(id)element
{
    [self add:element atIndex:_size];
}

/// 添加元素到指定位置
- (void)add:(id)element atIndex:(NSInteger)index
{
    [self rangeCheckForAdd:index];
    
    if (index == _size) { // 往最后面添加
        DoublyListNode *oldLast = _last;
        _last = DoublyListNodeMake(element, oldLast, NULL);
        if (oldLast == NULL) { // 这是链表的第1个节点
            _first = _last;
        } else {
            oldLast->next = _last;
        }
    } else {
        DoublyListNode *next = [self getNode:index];
        DoublyListNode *prev = next->prev;
        DoublyListNode *node = DoublyListNodeMake(element, prev, next);
        next->prev = node;
        if (prev == NULL) { // index == 0
            _first = node;
        } else {
            prev->next = node;
        }
    }
    _size++;
}

/// 设置index位置的元素
- (id)set:(id)element atIndex:(NSInteger)index
{
    DoublyListNode *node = [self getNode:index];
    id old = node->element;
    node->element = element;
    return old;
}

/// 获取index位置的元素
- (id)get:(NSInteger)index
{
    return [self getNode:index]->element;
}

/// 查看元素的索引
- (NSInteger)indexOf:(id)element
{
    if (element == nil) {
        DoublyListNode *node = _first;
        for (NSInteger i = 0; i < _size; i++) {
            if (node->element == nil) return i;
            node = node->next;
        }
    } else {
        DoublyListNode *node = _first;
        for (NSInteger i = 0; i < _size; i++) {
            if ([element isEqualTo:node->element]) return i;
            node = node->next;
        }
    }
    return ELEMENT_NOT_FOUND;
}

/// 删除index位置的元素
- (id)remove:(NSInteger)index
{
    DoublyListNode *node = [self getNode:index];
    DoublyListNode *prev = node->prev;
    DoublyListNode *next = node->next;
    
    if (prev == NULL) { // index == 0
        _first = next;
    } else {
        prev->next = next;
    }
    
    if (next == NULL) { // index == size - 1
        _last = prev;
    } else {
        next->prev = prev;
    }
    
    _size--;
    id element = node->element;
    free(node);
    return element;
}

/// 删除某元素
- (BOOL)removeElement:(id)element
{
    NSInteger index = [self indexOf:element];
    if (index != ELEMENT_NOT_FOUND) {
        [self remove:index];
        return YES;
    }
    return NO;
}

/// 清空所有元素
- (void)clear
{
    if (_size == 0) {
        return;
    }
    DoublyListNode *node = _first;
    for (NSInteger i = 0; i < _size; i++) {
        DoublyListNode *next = node->next;
        free(node);
        node = next;
    }
    _size = 0;
    _first = NULL;
    _last = NULL;
}

/// 打印所有元素
- (NSString *)description
{
    if ([self isEmpty]) {
        return @"size:0, items:[]";
    }
    DoublyListNode *node = _first;
    NSMutableString *string = [[NSMutableString alloc] initWithFormat:@"size:%lu, items:[", (unsigned long)_size];
    for (NSInteger i = 0; i < _size; i++) {
        if (i != 0) {
            [string appendString:@", "];
        }
        if (node->element == nil) {
            [string appendString:@"nil"];
        } else {
            [string appendString:[node->element description]];
        }
        node = node->next;
    }
    [string appendString:@"]"];
    return string.copy;
}

#pragma mark - Private

/// 获取index位置的节点
- (DoublyListNode *)getNode:(NSInteger)index
{
    [self rangeCheck:index];
    
    if (index < (_size >> 1)) {
        DoublyListNode *node = _first;
        for (NSInteger i = 0; i < index; i++) {
            node = node->next;
        }
        return node;
    } else {
        DoublyListNode *node = _last;
        for (NSInteger i = _size - 1; i > index; i--) {
            node = node->prev;
        }
        return node;
    }
}

- (void)rangeCheck:(NSInteger)index
{
    if (index < 0 || index >= _size) {
        [self outofBounds:index];
    }
}

- (void)rangeCheckForAdd:(NSInteger)index
{
    if (index < 0 || index > _size) {
        [self outofBounds:index];
    }
}

- (void)outofBounds:(NSInteger)index
{
    NSString *msg = [NSString stringWithFormat:@"out of bounds: index %lld beyond bounds [0 .. %lld]", (long long)index, (long long)_size];
    @throw [NSException exceptionWithName:NSRangeException reason:msg userInfo:nil];
}

@end
