//
//  NumberCalculation.h
//  algorithms
//
//  Created by Constant Cody on 1/3/20.
//  Copyright © 2020 Constant Cody. All rights reserved.
//

#ifndef NumberCalculation_h
#define NumberCalculation_h

struct ListNode {
    int val;
    struct ListNode *next;
}

/**
    两数之和（链表）
    给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

    如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

    您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 
    输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    输出：7 -> 0 -> 8
    原因：342 + 465 = 807

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/add-two-numbers
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* pre = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = pre;
    int carry = 0, sum = 0, x, y;
    while (l1 != NULL || l2 != NULL) {
        x = (l1 != NULL) ? l1->val : 0;
        y = (l2 != NULL) ? l2->val : 0;

        sum = carry + x + y;
        carry = sum / 10;

        struct ListNode* temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val = sum % 10;
        temp->next = NULL;

        cur->next = temp;
        cur = cur->next;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    if (carry > 0) {
        struct ListNode* temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->val = 1;
        temp->next = NULL;

        cur->next = temp;
    }
    
    return pre->next;
}


#endif /* NumberCalculation_h */
