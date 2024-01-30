// stack

#ifndef ___InStack
#define ___InStack

typedef struct {

    int max; // 스택 용량
    int ptr; // 스택 포인터
    int *stk // 스택의 첫 요소에 대한 포인터

} IntStack; // 스택이름

int Initialize (IntStack *s, int max); // 스택 초기화

int Push (IntStack *s, int x); // 데이터 입력

int Pop(IntStack *s, int *x); // 데이터 삭제

int Peek(const IntStack *s, int *x); // 데이터 피크

void Clear (IntStack *s); // 스택 비우기

int Capacity(const IntStack *s); // 스택의 최대 용량

int Size (const IntStack *s); // 스택의 데이터 개수

int IsEmpty (const IntStack *s); // 스택이 비어 있는지

int IsFull (const IntStack *s); // 스택이 가득 찼나요?

int Search (const IntStack *s, int x); // 스택에서의 검색

void Print (const IntStack *s); // 모든 데이터 츨력

void Terminate (IntStack *s);
#endif






