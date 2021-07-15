//
//  DoublyLinkedListDemo.m
//  AlgorithmDemo
//
//  Created by Cody on 2021/7/15.
//

#import "DoublyLinkedListDemo.h"
#import "DoublyLinkedList.h"
#import "Node.h"

@implementation DoublyLinkedListDemo

/// 测试双链表
+ (void)testDoublyLinkedList
{
    DoublyLinkedList *list = [[DoublyLinkedList alloc] init];
    [list add:@11];
    [list add:@22];
    [list add:@33];
    [list add:@44];
    [list add:@55 atIndex:0];           // [55, 11, 22, 33, 44]
    [list add:@66 atIndex:2];           // [55, 11, 66, 22, 33, 44]
    [list add:@77 atIndex:list.size];   // [55, 11, 66, 22, 33, 44, 77]
    NSLog(@"%@", list.description);
    
    [list remove:0];                    // [11, 66, 22, 33, 44, 77]
    [list remove:(list.size - 1)];      // [11, 66, 22, 33, 44]
    [list removeElement:@33];           // [11, 66, 22, 44]
    NSLog(@"%@", list.description);
}

/// 测试：leetcode_141_环形链表（https://leetcode-cn.com/problems/linked-list-cycle/）
+ (void)testHasCycle
{
    ListNode *head = ListNodeMake(10, NULL);
    ListNode *cur = head;
    for (int i = 1; i < 10; i++) {
        ListNode *node = ListNodeMake(10 + i, NULL);
        cur->next = node;
        cur = node;
    }
    // 最后一个节点的next指向NULL，此时无环！
    NSLog(@"是否有环：%@", [DoublyLinkedListDemo hasCycle:head] ? @"true" : @"false");
    
    // 最后一个节点的next指向第3个节点，因而有环！
    cur->next = head->next->next;
    NSLog(@"是否有环：%@", [DoublyLinkedListDemo hasCycle:head] ? @"true" : @"false");
}

#pragma mark - LeetCode

+ (BOOL)hasCycle:(ListNode *)head
{
    if (head == NULL || head->next == NULL) {
        return NO;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            return NO;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return YES;
}

@end
