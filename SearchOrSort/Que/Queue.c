// 큐, 함수 소스

#include <stdio.h>
#include <stdlib.h>
#include "../../Queue.h"

int Initialize (IntQueue *q, int max)
{
    q->num = q->front = q->rear = 0; // 준비 작업을 위해 전부 0으로 초기화
    if ((q->que = calloc(max, sizeof(int))) == NULL) {

        q->max = 0;
        return -1;
    }
    q -> max = max;
    return 0;
}

int Enque (IntQueue *q, int x) {
    if (q->num >= q->max)
        return -1; // 큐가 가득 참

    else {
        q-> num++;
        q-> que[q-> rear++] = x;
        // 다시

    }

}