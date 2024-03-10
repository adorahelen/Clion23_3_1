//
// Created by adora on 2024-03-10.
//

#ifndef CLION23_3_1_HASHH_H
#define CLION23_3_1_HASHH_H

#include "Member.h"

// 버킷을 나타내는 노드
typedef struct __node {
    Member data;
    struct __node *next;
}Node;

// 해시 테이블
typedef struct {
    int size;
    Node **table;
}ChainHash;

int Initialize(ChainHash *h, int size);
Node *Search(const ChainHash *h, const Member *x);
int Add(ChainHash *h, const Member *x);
int Remove(ChainHash *h, const Member *x);
void Dump(const ChainHash *h);
void Clear(ChainHash *h);
void Terminate(ChainHash *h);

#endif //CLION23_3_1_HASHH_H
