// 처음껀 가지치기, 두번째는 분기한정법 적용
// 8퀸 문제 풀이

#include <stdio.h>

int flag_a[8];
int flag_b[15];
int flag_c[15];
int pos[8];

void print(void)
{
    for (int i = 0; i < 8; i++)
        printf("%2d", pos[i]);
    putchar('\n');
}

void set(int i)
{
    for (int j = 0; j < 8; j++) {
        if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7]) { // debugging ! 하나 누락
            pos[i] = j;
            if(i == 7) // 모든 열에 배치를 마침
                print();
            else {
                flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
                set(i + 1); // 다음 열에 배치
                flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;

            }
        }
    }
}

int main (void)
{
    for (int i = 0; i < 8; i++)
        flag_a[i] = 0;
    for(int i =0; i < 15; i++)
        flag_b[i] = flag_c[i] = 0;

    set(0);

    return 0;
}