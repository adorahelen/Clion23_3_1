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

Node *Search(const ChainHash *h, const Member *x)
{
    int key = hash(x->no, h->size);
    Node *p = h->table[key];

    while (p != NULL) {
        if(p->data.no == x->no)
            return p;
        p = p->next;
    }
    return NULL;
}

int Add(ChainHash *h, const Member *x)
{
    int key = hash(x->no, h->size);
    Node *p = h->table[key];
    Node *temp;

    while (p != NULL) {
        if(p->data.no == x->no)
            return 1;
        p = p->next;
    }
    if ((temp = calloc(1, sizeof(Node))) == NULL)
        return 2;
    SetNode(temp, x, h->table[key]);
    h->table[key] = temp;
    return 0;
}
/*
 * 해쉬 함수가 키 값을 해시 값으로 변환한다.
 * 해시 값을 인덱스로 하는 버킷을 선택한다.
 * 버킷에 저장된 포인터가 가리키는 연결 리스트를 처음부터 순서대로 검색한다.
 * 키 값과 같은 값을 찾으면 키 값이 이미 등록된 상태이므로 추가에 실패한다.
 * */

int Remove(ChainHash *h, const Member *x)
{
    int  key = hash(x->no, h->size);    // 삭제하는 데이터의 해시값
    Node *p = h->table[key];            // 현재 선택한 노드
    Node **pp = &h->table[key];         // 현재 선택한 노드에 대한 포인터

    while (p != NULL) {
        if (p->data.no == x->no)    {   // 찾으면
            *pp = p->next;
            free(p);                    // 해제
            return 0;                   // 삭제 성공
        }
        pp = &p->next;
        p = p->next;                    // 다음 노드를 선택
    }

    return 1;                           // 삭제 실패(존재하지 않음)
}

/*--- 해시 테이블 덤프 ---*/
void Dump(const ChainHash *h)
{
    for (int i = 0; i < h->size; i++) {
        Node *p = h->table[i];
        printf("%02d  ", i);
        while (p != NULL) {
            printf("→ %d (%s)  ", p->data.no, p->data.name);
            p = p->next;
        }
        putchar('\n');
    }
}

/*--- 모든 데이터 삭제 ---*/
void Clear(ChainHash *h)
{
    for (int i = 0; i < h->size; i++) {
        Node *p = h->table[i];          // 현재 선택한 노드
        while (p != NULL) {
            Node *next = p->next;
            free(p);                    // 현재 선택한 노드의 메모리 해제
            p = next;                   // 다음 노드 선택
        }
        h->table[i] = NULL;
    }
}

/*--- 해시 테이블 종료 ---*/
void Terminate(ChainHash *h)
{
    Clear(h);               // 모든 데이터 삭제
    free(h->table);         // 해시 테이블 배열의 메모리 해제
    h->size = 0;            // 해시 테이블 크기를 0으로 초기화(clear)
}
