// stack

#ifndef ___InStack
#define ___InStack

typedef struct {

    int max; // 스택 용량
    int ptr; // 스택 포인터
    int *stk // 스택의 첫 요소에 대한 포인터

}; IntStack; // 스택이름

int Initialize (IntStack *s, int max);

int Push (IntStack *s, int x);

int Pop(IntStack *s, int *x);

int Peek