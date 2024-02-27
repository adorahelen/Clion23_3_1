// use divide solving
// 서로 공격하여 잡을 수 없도록, 8개의 퀸을 8*8 체스판에 배치하시오

// 퀸을 놓는 조합의 수는 16,777,216
/*
 * Rule 1: 각 열에 퀸을 1개만 배치합니다.
 *      2: 각 행에 퀸을 1개만 배치합니다.
 * */

#include <stdio.h>

int pos[8]; // 각 열에서 퀸의 위치

void print (void)
{
    for (int i = 0; i < 8; i++)
        printf("%2d", pos[i]);
    putchar('\n');
}

void set(int i)
{
    for(int j = 0; j < 8; j++) {
        pos[i] = j;
        if(i == 7)
            print();
        else
            set(i + 1);

    }
}

int main(void)
{
    set(0);

    return 0;
}

