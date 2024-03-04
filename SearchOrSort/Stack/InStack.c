// 스택 소스

# include <stdio.h>
# include <stdlib.h>
#include "InStack.h"

// 헤더파일에 정의된 함수들 구현 목록

int Initialize (IntStack *s, int max)
{
    s->ptr = 0; // 스택 포인터 값을 0으로 한다
    if ((s->stk = calloc (max, sizeof (int))) == NULL ) {
        //  배열 생성에 실패 했을 경우
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;

    /* * Pointer를 사용하여 구조체 원소에 접근할 때는 -> 사용해야한다.
     * 구조체 변수를 이용하여 구조체 원소에 접근할 때는 . 를 사용한다.
     *
     * : 포인터가 가리키는  주소에 데이터를 할당하려면 -> 사용
     * 포인터 이름 -> 맴버변수 이름 = 값(할당)
     * (*포인터 이름).맴버변수 이름 = 값
     * */

}   // stk는 내용물(스택을 가리키는  포인터), ptr 탑승칸(스택 포인터)

int Push (IntStack *s, int x)
{
    if (s->ptr  >=  s->max) // if it is full,
        return -1;

    s -> stk[s ->ptr ++] = x; // 후위 연산자라서 대입시킨 후에 한칸 증가시킨다.
    // s->stk[++s->ptr] = x; 이쪽이 증가된후에 대입시키는 코드
    return 0;
}

int Pop(IntStack *s, int *x)
{
    if (s-> ptr <= 0)
        return -1;

    // 이해안감 (GPT 질문 후 이해감), 결론은 한칸 전에 있던 값을 반환하는 함수
    // 그런데 왜 리턴 0일까?
    // 0이 리턴되면 정상적으로 지워졌다는 이야기, 그게 필요하다.
    // s->ptr을 1 감소시킨 후에 (--s->ptr), 감소된 위치에 해당하는 배열 s->stk의 값을 가져옵니다.
    //가져온 값을 포인터 x가 가리키는 메모리 위치에 대입합니다
    *x = s-> stk[--s->ptr];
    return 0;
}

int Peek (const IntStack *s, int *x)  // 엿보는 함수
{
    if ( s-> ptr <= 0)
        return -1;

    *x = s->stk[s->ptr -1];
    return 0;
}

void Clear (IntStack *s) {
    s->ptr = 0; // 기반이 되는 스택 포인터를 0으로
}

//나머지 함수들

int Capacity (const IntStack *s)
{
    return s->max; // 용량을 반환
}

int Size(const IntStack *s)
{
    return s ->ptr; // 스택에 쌓여있는 데이터 수
}

int IsEmpty (const IntStack *s)
{
    return s->ptr <= 0; // 비워 있으면 1 아니면 0 반환
}

int IsFull (const IntStack *s)
{
    return s->ptr >= s->max;
}

int Search (const IntStack *s, int x)
{
    for (int i = s->ptr -1; i >=0; i--)
        if (s->stk[i] == x)
            return i;

    return -1;
}

void Print(const IntStack *s)
{
    int i;
    for (int i = 0; i < s->ptr; i++)
        printf("%d ", s->stk[i]);
    putchar( '\n');
}

void Terminate (IntStack *s)
{
    if (s->stk != NULL)
        free(s->stk);

    s-> max = s->ptr = 0;
}



















