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



int main(int argc, const char * argv[]) {
    
    return 0;
}
