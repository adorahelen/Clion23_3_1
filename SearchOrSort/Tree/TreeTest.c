//
// Created by adora on 2024-03-03.
//
#include <stdio.h>
#include "Member.h"
#include "MyTree.h"


// 열거 자료형 "메뉴" 설정
typedef  enum {
    TERMINATE, ADD, REMOVE, SEARCH, PRINT
} Menu;

// 반환값 Menu 자료형, SelectMenu 함수 선언
Menu SelectMenu (void)
{
    int ch;
    do {
        printf("(1) Insert (2) Delete (3) FIND (4) Show (0) END: ");
        scanf("%d", &ch);
    } while(ch < TERMINATE || ch > PRINT);
    return (Menu)ch;
}

// 메인 함수
int main (void)
{
    Menu menu;
    BinNode *root = NULL; // 이진검색 트리의 루트노드 포인터
    do {

        Member x;
        BinNode *temp;

        switch (menu = SelectMenu()) {
            // 노드를 삽입* 삭제* 검색* 출력

            case ADD :
                x = ScanMember(" Insert ", MEMBER_NO | MEMBER_NAME);
                root = Add(root, &x);
                break;

            case REMOVE :
                x = ScanMember("Delete ", MEMBER_NO);
                Remove(&root, &x);
                break;

            case SEARCH :
                x = ScanMember("Search", MEMBER_NO);
                if ((temp = Search(root, &x)) != NULL)
                    PrintLnMember(&temp->data);
                break;

            case PRINT :
                puts(" ALL Print ");
                PrintTree(root);
                break;
        }
    } while (menu != TERMINATE);
    FreeTree(root);
    return 0;
}
