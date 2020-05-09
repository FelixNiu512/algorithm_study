//
//  main.c
//  单向循环链表
//
//  Created by Constant Cody on 5/9/20.
//  Copyright © 2020 Constant Cody. All rights reserved.
//

#include <stdio.h>
#include "stdlib.h"

#define MAXSIZE 20

/// 操作链表时返回的状态
typedef enum LINKLIST_STATUS {
    LINKLIST_STATUS_FAILURE = 0,
    LINKLIST_STATUS_SUCCESS
} Status;

typedef int NodeDataType;

typedef struct Node {
    NodeDataType data;
    struct Node *next;
    int size;
} Node, *LinkList;

Status list_init(LinkList *L) {
    *L = (LinkList)malloc(sizeof(Node));
    if (*L == NULL) return LINKLIST_STATUS_FAILURE;
    // 目前是空表，所以next指针指向自身
    (*L)->next = *L;
    (*L)->size = 0;
    return LINKLIST_STATUS_SUCCESS;
}

Status list_insert(LinkList L, int i, NodeDataType data) {
    // 合法性判断
    if (L == NULL || L->size >= MAXSIZE || i < 0 || i > L->size)
        return LINKLIST_STATUS_FAILURE;
    
    // 寻找目标位置的前一个结点
    LinkList preNode = L;
    int j = 0;
    while (j < i) {
        preNode = preNode->next;
        ++j;
    }
    
    // 创建新结点
    LinkList node = (LinkList)malloc(sizeof(Node));
    if (node == NULL) return LINKLIST_STATUS_FAILURE;
    node->data = data;
    node->next = preNode->next;
    preNode->next = node;
    
    // 更新结点数
    L->size++;
    return LINKLIST_STATUS_SUCCESS;
}

// 删除指定位置的结点
Status list_delete(LinkList L, int i) {
    // 合法性判断
    if (L == NULL || i < 0 || i >= L->size) return LINKLIST_STATUS_FAILURE;
    
    // 寻找目标位置的前一个结点
    LinkList preNode = L;
    int j = 0;
    while (j < i) {
        preNode = preNode->next;
        ++j;
    }
    
    // 要删除的结点
    LinkList delNode = preNode->next;
    preNode->next = delNode->next;
    free(delNode);
    
    // 更新结点数
    L->size--;
    return LINKLIST_STATUS_SUCCESS;
}

// 获取指定位置的数据
Status list_getData(LinkList L, int i, NodeDataType *data) {
    // 合法性判断
    if (L == NULL || i < 0 || i >= L->size) return LINKLIST_STATUS_FAILURE;
    
    // 从首元结点开始遍历，直到 j == i
    LinkList node = L->next;
    int j = 0;
    while (j < i) {
        node = node->next;
        ++j;
    }
    
    // 此时node就是指定位置的结点
    *data = node->data;
    return LINKLIST_STATUS_SUCCESS;
}

// 清空链表
Status list_empty(LinkList L) {
    // 合法性判断
    if (L == NULL) return LINKLIST_STATUS_FAILURE;
    
    LinkList delNode = L->next;
    while (delNode && delNode != L) {
        L->next = delNode->next;
        free(delNode);
        delNode = L->next;
    }
    
    // 最后更新结点数
    L->size = 0;
    return LINKLIST_STATUS_SUCCESS;
}

// 销毁
Status list_destroy(LinkList *L) {
    if (*L == NULL) return LINKLIST_STATUS_FAILURE;
    if ((*L)->size > 0) list_empty(*L);
    // 释放头结点
    free(*L);
    *L = NULL;
    return LINKLIST_STATUS_SUCCESS;
}

// 打印
Status list_print(LinkList L) {
    if (!L || L->size == 0) return LINKLIST_STATUS_FAILURE;
    LinkList node = L->next;
    while (node && node != L) {
        printf("%d\t", node->data);
        node = node->next;
    }
    printf("\n");
    return LINKLIST_STATUS_SUCCESS;
}

int main(int argc, const char * argv[]) {
    
    LinkList L;
    list_init(&L);
    for (int i = 0; i < 10; i++) {
        list_insert(L, i, 10+i);
    }
    list_print(L);
    
    list_delete(L, 1);
    list_print(L);
    
    list_empty(L);
    list_print(L);
    
    list_destroy(&L);
    list_print(L);
    
    return 0;
}
