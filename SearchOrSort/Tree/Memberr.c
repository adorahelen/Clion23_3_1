// 회원 데이터 Member(소스)
#include <stdio.h>
#include <string.h>
#include "Member.h"

/*--- 회원 번호 비교 함수 ---*/
int MemberNoCmp(const Member *x, const Member *y)
{
    return x->no < y->no ? -1 : x->no > y->no ? 1 : 0;
}


/*--- 회원 데이터(번호와 이름)를 출력(줄 바꿈 있음) ---*/
void PrintLnMember(const Member *x)
{
    printf("%d %s\n", x->no, x->name);
}

/*--- 회원 데이터(번호와 이름)를 읽음 ---*/
Member ScanMember(const char *message, int sw)
{
    Member temp;
    printf("%s Input the data \n", message);
    if (sw & MEMBER_NO)   { printf("Number: ");  scanf("%d", &temp.no);  }
    if (sw & MEMBER_NAME) { printf("Name: ");  scanf("%s", temp.name); }
    return temp;
}
