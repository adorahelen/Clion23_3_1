// 큐, 함수 소스

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int Initial (IntQueue *q, int max)
{
    q->num = q->front = q->rear = 0; // 준비 작업을 위해 전부 0으로 초기화
    if ((q->que = calloc(max, sizeof(int))) == NULL) {

        q->max = 0;
        return -1;
    }
    q -> max = max;
    return 0;
}

int inQue (IntQueue *q, int x) {
    if (q->num >= q->max)
        return -1; // 큐가 가득 참

    else {
        q-> num++;
        q-> que[q-> rear++] = x; // 대입하고 증가
        if (q->rear == q-> max) // 꽉 찼으면
            q->rear = 0;
        return 0;
    } // 인큐할 데이터를 저장하고, rear와 num 값을 1만큼 증가하면 인큐 작업이 끝난다.
}

int outQue (IntQueue *q, int *x)
{
    if (q->num <=0)
        return -1;
    else {
        q->num--; // 덱의 원소 개수를 1개 감소시킨다.
        *x = q->que[q->front++];
        // 덱의 프런트에 있는 값을 *x에 대입한 다음 1을 중가

        if (q->front == q-> max)
            q-> front = 0;
        // 덱이 환형 구조이기 때문에, 마지막 인데스에 도달하면 0으로 설정
        return 0;
    }
} // 덱에서 원소를 꺼내어 'x'에 저장하고, 그 동안에 덱의 상태를 유지한다.
  // 만약 덱이 비어있는 경우에은 '-1'을 반환하여 덱이 비어있음을 나타낸다.

  int Peek (const IntQueue *q, int *x)
  {
    if (q->num <= 0)
        return -1;
    *x = q->que[q->front];
      return 0;
  }

  void Clear (IntQueue *q)
  {
    q->num = q->front = q->rear = 0;
  }


int Capacity (const IntQueue *q)
{
    return q-> max;
}

int Size (const IntQueue *q)
{
    return q->num;
}

int IsEmpty (const IntQueue *q)
{
    return q->num <= 0;
}

int IsFull (const IntQueue *q)
{
    return q->num >= q->max; // 맞으면 1, 틀리면 0을 반환한다.
}

int Search (const IntQueue *q, int x)
{
    for (int i = 0; i < q->num; i++ ) {
        int idx;
        if (q->que[idx = (i + q->front) % q -> max ] == x) // idx에 대입하는 현재 위치의 인덱스를 구하는 식 이해 안감;
            // 프로세스 스케쥴링 공식처럼, 더하고 나눈 다음 나머지를 통해 구한다.
            return idx; // 검색 성공식 인덱스 반환
    }
    return -1; // 검색 실패시 -1 반환
}

void Print(const IntQueue *q) {
    for (int i = 0; i < q->num; i++)
        printf("%d ", q->que[(i + q->front) % q->max]); // 검색하는 위치의 인덱스 계산 방법은 Search 함수와 동일하다.
    putchar('\n');
}

void Terminate (IntQueue *q)
{
    if (q->que != NULL)
        free(q->que); // 할당한 배열 해제
    q->max = q->num = q->front = q->rear = 0; // 전부 0으로 초기화
}
