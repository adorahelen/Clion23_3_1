//
// Created by adora on 2024-02-01.
//

#ifndef CLION23_3_1_QUEUE_H
#define CLION23_3_1_QUEUE_H

// 큐를 구현하는 구조체
typedef struct {
    int max; // 큐 최대 용량
    int num; // 현재의 요소 개수
    int front;
    int rear;
    int *que // 큐의 포인터 (맨앞)
} IntQueue;

// @함수의 요소는 이름에 구애받지 않는다.
int Initial (IntQueue *q, int max);
int inQue (IntQueue *q, int x);

int outQue (IntQueue *q, int *X); // inQue와 다르게 포인터를 사용하는 이유 설명하기
int Peek (const IntQueue *q, int *x); // 꼭대기 훔쳐보기
int Search (const IntQueue *q, int x);

void Clear (IntQueue *q); // 초기화
int Capacity (const IntQueue *q); // 최대 용량
int Size (const IntQueue *q); // 현재 개수
int IsEmpty (const IntQueue *q);
int IsFull (const IntQueue *q);
void Print(const IntQueue *q);
void Terminate (IntQueue *q);

#endif //CLION23_3_1_QUEUE_H
