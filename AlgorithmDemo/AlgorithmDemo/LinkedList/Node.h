//
//  Node.h
//  AlgorithmDemo
//
//  Created by Cody on 2021/7/14.
//

#ifndef Node_h
#define Node_h

#define ELEMENT_NOT_FOUND -1L

// 单链表的节点
typedef struct ListNode {
    id element;
    struct ListNode *next;
} ListNode;

static inline ListNode*
ListNodeMake(id element, struct ListNode *next)
{
    ListNode *node = malloc(sizeof(ListNode));
    if (node != NULL) {
        node->element = element;
        node->next = next;
    }
    return node;
}

// 双链表的节点
typedef struct DoublyListNode {
    id element;
    struct DoublyListNode *prev;
    struct DoublyListNode *next;
} DoublyListNode;

static inline DoublyListNode*
DoublyListNodeMake(id element, struct DoublyListNode *prev, struct DoublyListNode *next)
{
    DoublyListNode *node = malloc(sizeof(DoublyListNode));
    if (node != NULL) {
        node->element = element;
        node->prev = prev;
        node->next = next;
    }
    return node;
}

#endif /* Node_h */
