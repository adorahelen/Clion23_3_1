//
// Created by adora on 2024-03-01.
// 형제 노드의 순서가 있는짖, 없는지에 따라 트리를 두 종류로 분류한다.
/*순서를 따지면 Ordered tree, 따지지 않으면 무순서 트리 Unordered tree
 *
 * 1. 너비 우선 탐색 BFS
 * 왼쪽에서 시작해서 오른쪽으로
 * 하나의 레벨 (행)이 끝나면 다음 행으로(레벨)
 *
 * 2. 깊이 우선 탐색 DFS
 * 하나의 열을 깊이 (끝까지) 파고
 * 한 칸 이동하여 다시 하나의 열을 끝까지
 *  (전위 중위 후위 순회는 이 DFS에서 사용된다)
 *  Pre in post
 * */

#ifndef CLION23_3_1_MYTREE_H
#define CLION23_3_1_MYTREE_H

#include "Member.h"

// 노드 정의 (데이터 타입 맴버를 담고있는.. 그 맴버는 data라고 명명)
typedef struct __bnode {
    Member data; // 데이터이며 "헤더파일"에 정의되어 있는 내용을 데이터로 사용한다.
    struct __bnode *left; // 이진트리 좌측을 나타냄
    struct __bnode *right; // 이진트리 우측을 나타낸다.
} BinNode;

BinNode *Search(BinNode *p, const Member *x); // 검색용 함수
BinNode *Add(BinNode *p, const Member *x); // 노드 삽입 용 합수
int Remove (BinNode **root, const Member *x); // 노드 삭제용 함수
void PrintTree (const BinNode  *p); // 모든 노드 출력 함수
void FreeTree (BinNode *p); // 모든 노드 삭제 함수
#endif //CLION23_3_1_MYTREE_H
