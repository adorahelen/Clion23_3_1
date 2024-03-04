//
// Created by adora on 2024-03-03.
//
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "List.h"

// 노드를 동적으로 생성
static Node *AllocNode(void)
{
    return calloc(1, sizeof(Node));

}

// n이 가리키는 노드의 각 맴버에 값을 설정
static void SetNode(Node *n, const Member *x,
                    const Node *next) {

    n->data = *x; // 데이터
    n->next = next;  // 뒤쪽 포인터
}

// 연결 리스트를 초기화
void initialize(List *list)


