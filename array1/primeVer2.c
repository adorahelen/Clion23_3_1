//ver2

#include <stdio.h>

int main (void)
{
    int prime[500];
    int ptr = 0;
    unsigned long counter = 0;

    prime[ptr++] = 2; // prime[1] = 2;

    for(int n = 3; n <= 1000; n += 2) {
        int i;

        // ptr이 1이므로 안쪽 for 문은 실질적으로 건너뛴다.
        for (i = 1; i < ptr; i++) {
            counter++;

            if (n % prime[i] == 0)
                break;
        }

        if (ptr == i)
            prime[ptr++] = n; //ptr[1] = 3;
    }
    for (int i = 0; i < ptr; i++)
        printf("%d\n", prime[i]);
    printf("How many divison occured : %lu\n", counter);
    return 0;

}

// 같은 출력값이지만, 연산횟수가 현저히 줄었다. 7만에서 1만으로;