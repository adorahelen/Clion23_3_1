// 재귀 알고리즘 분석
/*#include <stdio.h>

void recur (int n) // 재귀함수
{
    if (n > 0) {
        recur(n - 1);
        printf("%d\n", n);
        recur(n - 2);
    }
}
int main(void)
{
    int x;
    printf(" Enter the Integer : ");
    scanf("%d", &x);
    recur(x);

    return 0;
}*/
// 재귀 함수 recur를 메모이제이션으로 구현
/* 어떤 문제에 대한 해답을 얻으면 그것을 메모
 * 중복되는 계산 횟수를 최소화*/
#include <string.h>
#include <stdio.h>
static char memo [128][1024];

void recur(int n) {
    if (memo[n + 1][0] != '\0')
        printf("%s", memo[n+1]); // 1. 메모 출력

    else {
        if (n > 0) {
            recur(n-1);
            printf("%d\n", n);
            recur(n-2); // 2.

            sprintf(memo[n + 1], "%s%d\n%s", memo[n], n, memo[n -1]); // 3.
        } else {
            strcpy(memo[n+1], "");
        }
    }
}
int main (void)
{
    int x;
    printf("Enter the num : ");
    scanf("%d", &x);

    recur(x);

    return 0;
}