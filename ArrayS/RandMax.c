// 난수를 이용한 배열 최대값 구하기
# include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maxof (const int a[], int n);

int main (void) {
    int number;
    printf("pepole count :");
    scanf("%d", &number);
    int *height = calloc(number, sizeof (int));
    srand(time(NULL));

    for ( int i =0; i<number; i++){
        height[i] = 100 + rand() % 90 + 50; // 범위를 150cm ~ 200cm 로 조정하려면?
        printf("height[%d] = %d\n", i,height[i]);
    }
    printf("The max is %d", maxof(height, number));
    free(height);
    return 0;
}

int maxof (const int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max ) max = a[i];
    return max;
}
