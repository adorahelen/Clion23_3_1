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

typedef struct __bnode {
    Member data; // 데이터
    struct __bnode *left;
    struct __bnode *right;
} BinNode;

BinNode *Search(BinNode *p, const Member *x);
BinNode *Add(BinNode *p, const Member *x);
int Remove (BinNode **root, const Member *x);
void PrintTree (const BinNode  *p);

void FreeTree (BinNode *p);
#endif //CLION23_3_1_MYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "BinTree.h"

static BinNode *AllocBinNode (void)
{
    return calloc(1, sizeof(BinNode));
}

static void SetBinNode (BinNode *n, const Member *x, const BinNode *left, const BinNode *right)
{
n->data = *x;
n->left = left;
n->right = right;
}




