// 예전에 배운 리스트가 순서대로 데이터를 나열하는 자료구조 (포인터 사용)
// 트리는 데이터 시이의 계층 관계를 나타내는 자료구조

// 트리를 구성하는 요소는 Node 그리고 edge

// 이진 검색 트리 만들기(메인 먼저-> 함수-> 헤더)
#include <stdio.h>
#include "Member.h"
#include "BinTree.h"
#include "MyTree.h"

typedef  enum {
    TERMINATE, ADD, REMOVE, SEARCH, PRINT
} Menu;

Menu SelectMenu (void)
{
    int ch;
    do {
        printf("(1) Insert (2) Delete (3) FIND (4) Show (0) END: ");
        scanf("%d", &ch);
    } while(ch < TERMINATE || ch > PRINT);
    return (Menu)ch;
}

int main (void)
{
    Menu menu;
    BinNode *root = NULL;
    do {
        Member x;
        struct __bnode temp;
        switch (menu= SelectMenu()) {

            case ADD :
                x = ScanMember

        }
    }
}