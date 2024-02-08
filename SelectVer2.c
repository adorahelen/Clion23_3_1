// 1. 셸 정렬
// 단순 삽입 정렬의 장점은 살리고 단점은 보완
// - 정렬할 배열의 요소를 그룹으로 나눠 각 그룹별로 단순 삽입 정렬 수행 (분할)
// 그 그룹을 합치면서 정렬을 반복하여 요소의 이동 횟수를 줄이는 방법. (합병)
// (퀵 정렬 도입 전까지 제일 빠른 알고리즘)

#include <stdio.h>
#include <stdlib.h>

void shell(int a[], int n)
{
    for(int h = n/2; h > 0; h/=2)
        for(int i = h; i<n; i++) {
            int tmp = a[i];
            int j;
            for (j = i - h; j >= 0 && a[j] > tmp; j -= h) // *
                a[j + h] = a[j];
            a[j + h] = tmp;
        }
}

int main(void)
{
    int nx;
    puts("Shell Sorting !");
    printf(" Elemental nums : ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof (int));
    for(int i = 0; i<nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    shell(x, nx);
    puts(" Sorted Assending");
    for(int i = 0; i < nx; i++)
        printf("x[%d] : %d\n", i, x[i]);

    free(x);
    return 0;
}