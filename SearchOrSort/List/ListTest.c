//
// Created by adora on 2024-03-08.

#include <stdio.h>
#include "Member.h"
#include "List.h"

typedef enum {
    TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR, PRINT_CRNT,
    RMV_CRNT, SRCH_NO, SRCH_NAME, PRINT_ALL, CLEAR
}Menu;


//메뉴 선택
Menu SelectMenu (void) {

    int i, ch;
    char *mstring[] = {
            "Head Node Insert", "Tail Node Insert", "Head Node Delete",
            "Tail Node Delete", "Selected Node Print", "Selected Node Delete",
            "Searching use Number", "Searching use Name", "Every Node Print",
            "All Node Delete",

    };
    do {
        for (i = TERMINATE; i < CLEAR; i++) {
            printf("(%2d) %-18.18s", i+1, mstring[i]);
            if ((i%3) == 2)
                putchar('\n');
        }
        printf("(0) EXIT : ");
        scanf("%d", &ch);
    } while (ch < TERMINATE || ch > CLEAR);

    return (Menu)ch;
}


int main(void)
{
    Menu menu;
    List list;
    initialize(&list); // 연결리스트를 초기화

    do {
        Member x;
        switch (menu = SelectMenu()) {
            case INS_FRONT:
                x = ScanMember("Insert Head", MEMBER_NO | MEMBER_NAME);
                InsertFront(&list, &x);
                break;

            case INS_REAR:
                x = ScanMember("Insert Tail", MEMBER_NO | MEMBER_NAME);
                InsertRear(&list, &x);
                break;

            case RMV_FRONT:
                RemoveFront(&list);
                break;
                
            case RMV_REAR:
                RemoveRear(&list);
                break;
                
            case PRINT_CRNT:
                PrintCurrent(&list);
                break;

            case RMV_CRNT:
                RemoveCurrent(&list);
                break;

            case SRCH_NO :
                x = ScanMember("Searching", MEMBER_NO);
                if (search(&list, &x, MemberNoCmp) != NULL)
                    PrintLnCurrent(&list);
                else
                    puts("IS there Nothing that Nums data");
                break;

            case SRCH_NAME:
                x = ScanMember("Searching", MEMBER_NAME);
                if (search(&list, &x, MemberNameCmp) != NULL)
                    PrintLnCurrent(&list);
                else
                    puts(" No data, what you find Name.");
                break;

            case PRINT_ALL :
                Print(&list);
                break;

            case CLEAR :
                Clear(&list);
                break;
        }
    } while(menu != TERMINATE);
    Terminate(&list);

    return 0;
}