#include<stdio.h>
// 진수변환 프로그램
#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

int conv (unsigned x, int n, char d[])
{
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digits = 0;

    // 이해가 잘 가지 않는 아래에 알고리즘은,
    // 주어진 10진수를 x를 기수가 n인 진법으로 변환하고, 결과물을 저장 배열[d]하는 과정
    if (x == 0) // 내려 받은 x가 0이면
        d[digits++] = dchar[0]; // 0을 대입한다
    else
        while (x) {
            d[digits++] = dchar[x % n]; // 계속 n으로 나눈 나머지를 저장
            x /= n;
        }
    for (int i = 0; i < digits /2; i++)
        swap(char, d[i], d[digits - i - 1]); // 배열 d를 역순으로 정렬

    return digits;
}

int main (void) {

    puts("change 10jinsu => to another");

    int retry; // 0 || 1

    do { // 1 => 전체적인 틀 while()조건 만족시 계속 반복
        unsigned no; // 변환할 정수
        int cd; // 기수
        char cno[512]; // 변환한 값의 각 자리의 숫자를 저장하는 문자 배열

        printf("please Enter the +Num (not -Num or 0)\n"); // 변환하는건 음수가 아닌 정수
        scanf("%u", &no);

        do { // 2 => 잘못된 숫자 입력시, 재입력을 요구
            printf("what is your pick? (2jinsu ~ 36jinsu): ");
            scanf("%d", &cd);
        } while (cd < 2 || cd > 36 );

        int dno  = conv(no, cd, cno); // 변환할 정수, 몇진수인지(기수), 변환후 저장할 배열

        printf("it be changed '%d'jinsu  ", cd);
        for (int i = 0; i < dno; i++)
            printf("%c", cno[i]);
        printf("  is it.\n");

        printf("if you wanna go try one more?(say yes==1, no==0) : ");
        scanf("%d", &retry);

    } while (retry == 1);

    return 0;
}
// 100% 이해 NO, 복습 필요