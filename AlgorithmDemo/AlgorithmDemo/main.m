//
//  main.m
//  AlgorithmDemo
//
//  Created by Cody on 2021/7/14.
//

#import <Foundation/Foundation.h>
#import "StackDemo.h"
#import "DoublyLinkedList.h"

/// 测试：有效的符号
void testStack()
{
    NSArray<NSString *> *expArray = @[@"()[]{}", @"([)]", @"{[]}", @"{[])}"];
    for (NSString *exp in expArray) {
        NSLog(@"%@ isValid: %@", exp, [StackDemo isValidBrackets:exp] ? @"true" : @"false");
    }
}

/// 测试双链表
void testDoublyLinkedList()
{
    DoublyLinkedList *list = [[DoublyLinkedList alloc] init];
    [list add:@11];
    [list add:@22];
    [list add:@33];
    [list add:@44];
    [list add:@55 atIndex:0];           // [55, 11, 22, 33, 44]
    [list add:@66 atIndex:2];           // [55, 11, 66, 22, 33, 44]
    [list add:@77 atIndex:list.size];   // [55, 11, 66, 22, 33, 44, 77]
    NSLog(@"%@", list.toString);
    
    [list remove:0];                    // [11, 66, 22, 33, 44, 77]
    [list remove:(list.size - 1)];      // [11, 66, 22, 33, 44]
    [list removeElement:@33];           // [11, 66, 22, 44]
    NSLog(@"%@", list.toString);
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        testDoublyLinkedList();
    }
    return 0;
}
