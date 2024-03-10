//
// Created by adora on 2024-03-10.
//
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "HashH.h"

static int hash(int key, int size){
    return key % size;
}

static void SetNode(Node *n, const Member *x, const Node *next)
{
    n->data = *x; // 데이터
    n->next = next; // 다음 노드에 대한 포인터
}

int Initialize(ChainHash *h, int size) {
    int i;
    if ((h->table = calloc(size, sizeof(Node *))) == NULL) {
        h->size = 0;
        return 0;
    }
    h->size = size;
    for(i = 0; i < size; i++)
        h->table[i] = NULL;
    return 1;
}

Node *Search(const)