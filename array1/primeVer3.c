// ver3
#include <stdio.h>

int main (void)
{
    int prime[500]; // 소수 저장하는 배열
    int ptr = 0; // 이미 얻은 소수 개수
    unsigned long counter = 0;

    prime[ptr++] = 2;
    prime[ptr++] = 3;

    for (int n = 5; n <= 1000; n+=2) { // 홀수만을 대상
        int i;
        int flag = 0;
        for (i = 1; counter++, prime[i] * prime[i] <= n; i++) {
            // 조건 : 카운터 1증가, i * i 가 n보다 작으면
            counter++; // 위는 곱하기, 밑에는 나누기를 카운트하여 연산 총 횟수를 구함
            if ( n % prime[i] == 0 ) { // 제곱을 나누는 것이 소수를 구하기 더욱 쉽다
                flag = 1;
                break;
            }
        }
        if ( ! flag ) // 마지막까지 나누어 떨어지지 않았다면
            prime[ptr++] = n;
    }
    for (int i = 0; i < ptr; i++)
        printf("%d\n", prime[i]);

    printf(" * count + / count : %lu\n", counter);
    return 0;
}