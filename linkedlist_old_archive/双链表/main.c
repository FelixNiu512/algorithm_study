//
//  main.c
//  双链表
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
    struct Node *prior, *next;
    int size;
} Node, *LinkList;

// 初始化
Status list_init(LinkList *L) {
    *L = (LinkList)malloc(sizeof(Node));
    if (*L == NULL) return LINKLIST_STATUS_FAILURE;
    // 此时还没有首元结点，所以头结点的prior、next指针值为NULL
    (*L)->prior = NULL;
    (*L)->next = NULL;
    (*L)->size = 0;
    return LINKLIST_STATUS_SUCCESS;
}

// 打印
Status list_print(LinkList L) {
    if (!L || L->size == 0) return LINKLIST_STATUS_FAILURE;
    LinkList node = L->next;
    while (node) {
        printf("%d\t", node->data);
        node = node->next;
    }
    printf("\n");
    return LINKLIST_STATUS_SUCCESS;
}

// 插入
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
    // 先处理新结点的赋值操作
    node->data = data;
    node->prior = preNode;
    node->next = preNode->next;
    // 更新node->next结点的前驱指针
    if (node->next) node->next->prior = node;
    // 更新preNode的next指针
    preNode->next = node;
    
    // 更新结点数
    L->size++;
    return LINKLIST_STATUS_SUCCESS;
}

// 删除
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
    // 如果delNode不是尾结点
    if (delNode->next) delNode->next->prior = preNode;
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
    while (delNode) {
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
