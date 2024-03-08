//
// Created by adora on 2024-03-03.
//

#ifndef CLION23_3_1_LIST_H
#define CLION23_3_1_LIST_H

#include "Member.h"

// 데이터 타입 노드 정의
typedef struct __node {
    Member data; // 데이터
    struct __node *next; // 뒤쪽 포인터
} Node;
// 자신과 같은 자료형의 객체를 가리키는 데이터를 가지고 있는 자료구조를 "자기 참조 형"이라고 한다.
/*
 * 자기 참조는 '자기 자신을 가리키는 포인터'가 아니라,
 * 자기 자신과 같은 자료형의 객체를 가리키는 포인터를 맴버로 가지고 있다.
 * 라는 뜻이다. == (struct__node)를 맴버로 가지고 있다.
 * */


// 데이터 타입 연결 리스트 정의
typedef struct {
    Node *head; // 머리 노드
    Node *crnt; // 선택한 노드
} List;

void initialize(List *list); // 연결 리스트 초기화

Node *Search(List *list, const Member *x,
             int compare(const Member *x, const Member *y));
// x와 동일한 노드 검색

void insertFront(List *list, const Member *x);
// 머리에 노드를 삽입
void insertRear(List *list, const Member *x);
// 꼬리에 노드를 삽입


void RemoveFront(List *list); // 머리 노드 삭제
void RemoveRear(List *list); // 꼬리 노드 삭제
void RemoveCurrent(List *list); // 선택한 노드 삭제
void Clear(List *list); //모든 노드 삭제

void PrintCurrent(const List *list); // 하나출력
void PrintCurrent(const List *list); //하나출력 + ln
void Print(const List *list); // 모든 노드 출력
void Terminate(List *list); // 연결리스트 종료

#endif //CLION23_3_1_LIST_H
