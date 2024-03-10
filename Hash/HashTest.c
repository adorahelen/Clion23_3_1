//
// Created by adora on 2024-03-10.
//
// 체인 해시(ChainHash)의 사용
#include <stdio.h>
#include "Member.h"
#include "HashH.h"

/*--- 메뉴 ---*/
typedef enum {
    TERMINATE, ADD, DELETE, SEARCH, CLEAR, DUMP
} Menu;

/*--- 메뉴 선택 ---*/
Menu SelectMenu(void)
{
    int ch;
    do {
        printf("(1) ADD (2) Delete (3) Search (4) All Delete (5) Dump (0) Exit: ");
        scanf("%d", &ch);
    } while (ch < TERMINATE || ch > DUMP);
    return (Menu)ch;
}

/*--- 메인 ---*/
int main(void)
{
    Menu menu;              // 메뉴
    ChainHash hash;         // 해시 테이블
    Initialize(&hash, 13);  // 해시 테이블 초기화
    do {
        int result;
        Member x;
        Node *temp;
        switch (menu = SelectMenu()) {
            case ADD : /*--- 데이터 추가 ---*/
                x = ScanMember("AddED", MEMBER_NO | MEMBER_NAME);
                result = Add(&hash, &x);
                if (result)
                    printf("\aError: Failed Adding(%s).\n",
                           (result == 1) ? "Already Registered" : "No Memory ");
                break;

            case DELETE : /*--- 데이터 삭제 ---*/
                x = ScanMember("Delete", MEMBER_NO);
                result = Remove(&hash, &x);
                if (result == 1)
                    printf("\aError: No this Number's data...\n");
                break;

            case SEARCH : /*--- 데이터 검색 ---*/
                x = ScanMember("Searching", MEMBER_NO);
                temp = Search(&hash, &x);
                if (temp == NULL)
                    printf("\aFailed Searching.\n");
                else {
                    printf("Success Searching. ");
                    PrintLnMember(&temp->data);
                }
                break;

            case CLEAR : /*--- 모든 데이터 삭제 ---*/
                Clear(&hash);
                break;

            case DUMP : /*--- 해시 테이블 덤프 ---*/
                Dump(&hash);
                break;
        }
    } while (menu != TERMINATE);
    Terminate(&hash);                           // 해시 테이블 종료

    return 0;
}
