// Created by adora on 2024-02-18.
// 1,2,3,4,5 (Ascending) || 5,4,3,2,1 (Descending)
// 정렬 알고리즘은 안정된(stable) / 불안정된으로 나눈다.
// (주)메모리 == 내부정렬 || 보조기억장치 == 외부정렬
// 핵심요소 {교환, 선택, 삽입}

// Not real QuickSort
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x,y) do{type t= x; x= y; y=t;} while (0)

void partition (int a[], int n)
{
    int pl = 0; // 왼쪽 커서
    int pr = n - 1; // 오른쪽 커서
    int x = a[n /2]; // 피벗은  가운데 요소 선택

    do {
        while (a[pl] < x) pl++;
        while (a[pl] > x) pr--;
        if (pl <= pr) {
            swap(int, a[pl], a[pr]);
            // 배열 a를 피벗 x를 기준으로 나눈다.
            pl++;
            pr--;
        }
    } while (pl <= pr);
    printf("Pivot value is %d. \n",x);
    printf("Under the pivot Grub \n");
    for(int i = 0; i <= pl -1; i++)
        printf("%d ", a[i]);
    putchar('\n');

    if(pl > pr + 1) {
        printf(" == same Pivot is \n");

        for(int i = pr + 1; i <= pl -1; i++)
            printf("%d ", a[i]);
        putchar('\n');
    }

    printf("Over the pivot Grub\n");
    for(int i = pr + 1; i < n; i++)
        printf("%d ", a[i]);
    putchar('\n');
}

int main (void)
{
    int nx;
    puts(" Divided Array. ");
    printf("Counting Nums: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));
    for(int i = 0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }

    partition(x, nx);
    free(x);

    return 0;

}
