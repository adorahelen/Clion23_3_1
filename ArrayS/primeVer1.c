//ver1

#include <stdio.h>

int main (void)
{
    unsigned long counter = 0;

    for (int n =2; n <= 1000; n++) { // n++ (숫자)
        int i;

        for (i = 2; i < n; i++) { // i++ (나누는 수)
            counter++;
            if (n % i == 0) // 나누어 떨어지면 소수가 아님
                break;
        }
        if (n == i) // 서로 증가되어도 마지막까지 나누어떨어지지 않는다?
            printf("%d\n", n); // 그럼 너는 소수
    }
    printf("How many divison has occured: %lu\n", counter);
    return 0;
}