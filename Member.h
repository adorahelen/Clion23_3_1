//
// Created by adora on 2024-03-02.
//

#ifndef CLION23_3_1_MEMBER_H
#define CLION23_3_1_MEMBER_H

typedef struct {
    int no; // 번호
    char name [20]; // 이름
}Member;

#define MEMBER_NO   1
#define MEMBER_NAME 2

int MemberNoCmp(const Member *x, const Member *y); // 회원번호비교
int MemberNameCmp(const Member *x, const Member *y); // 회원이름비교
void PrintMember(const Member *x); // 회원 데이터를 출력(줄 바꿈 없이)
void PrintLnMember(const Member *x);
Member ScanMember(const char *message, int sw);
#endif //CLION23_3_1_MEMBER_H
