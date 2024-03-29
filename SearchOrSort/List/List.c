//
// Created by adora on 2024-03-03.
//
#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "List.h"

// 노드를 동적으로 생성
static Node *AllocNode(void)
{
    return calloc(1, sizeof(Node));

}

// n이 가리키는 노드의 각 맴버에 값을 설정
static void SetNode(Node *n, const Member *x, const Node *next)
{

    n->data = *x;
    n->next = next;
}

// 연결 리스트를 초기화
void initialize(List *list)
{
    list->head = NULL;
    list->crnt = NULL;
}

Node *search(List *list, const Member *x, int compare(const Member *x, const Member *y))
{
    Node *ptr = list->head;
    while(ptr != NULL) {
        if (compare(&ptr->data, x) == 0) {
            list->crnt = ptr;
            return ptr; // 키 값이 같아서 검색에 성공한 경우
        }
        ptr = ptr->next; // (성공한 경우)다음 노드를 선택
    }
    return NULL; // 검색에 실패한 경우
}

void InsertFront (List *list, const Member *x)
{
    Node *ptr = list->head;
    list->head = list->crnt = AllocNode();
    SetNode(list->head, x, ptr);
}

void InsertRear (List *list, const Member *x)
{
    if (list->head == NULL)
        InsertFront(list, x);
    else {
        Node *ptr = list->head;
        while(ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = list->crnt = AllocNode();
        SetNode(ptr->next, x, NULL);
    }
}


void RemoveFront(List *list) {
    if (list->head != NULL) {
        Node *ptr = list->head->next; // 두번째 노드에 대한 포인터
        free(list->head); // 머리 노드를 해제
        list->head = list->crnt = ptr; // 새로운 머리 노드
    }
}

void RemoveRear (List *list)
{
    if (list->head != NULL) {
        if ((list->head)->next == NULL) // 노드가 한개만 있는 경우
            RemoveFront(list);

        else {
            Node *ptr = list->head;
            Node *pre;
            while (ptr->next != NULL) {
                pre = ptr;
                ptr = ptr->next;
            }

            pre->next = NULL;
            free(ptr);
            list->crnt = pre;

        }
    }
}

void RemoveCurrent(List *list)
{
    if(list->head != NULL) {
        if(list->crnt == list->head)
            RemoveFront(list);
        else{
            Node *ptr = list->head;
            while (ptr->next != list->crnt)
                ptr = ptr->next;

            ptr->next = list->crnt->next;
            free(list->crnt);
            list->crnt = ptr;

        }
    }
}


// 모든 노드를 삭제
void Clear (List *list)
{
    while(list->head != NULL) // 텅 빌 때까지
        RemoveFront(list); // 머리 노드를 삭제
        list->crnt = NULL;
}

void PrintCurrent (const List *list)
{
    if (list->crnt == NULL)
        printf("Is there Nothing...");
    else
        PrintMember(&list->crnt->data);
}

void PrintLnCurrent (const List *list)
{
    PrintCurrent(list);
    putchar('\n');
}

void Print (const List *list)
{
    if (list->head == NULL)
        puts("No Node,,,");
    else {
        Node *ptr = list->head;
        puts("<<<All Showing!>>>");
        while(ptr != NULL) {
            PrintLnMember(&ptr->data);
            ptr = ptr->next; // 다음 노드를 선택
        }
    }
}

void Terminate (List *list)
{
    Clear(list);
}