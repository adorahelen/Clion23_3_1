//
// Created by adora on 2024-02-21.
//
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{type t = x; x = y; y = t; } while(0)

void quick (int a[], int left, int right)
{
    int pl = left;
    int pr = right;
    int x = a[(pl + pr) / 2];

    // 재귀호출 방법을 사용했음
    do {
        while (a[pl] < x) pl++;
        while (a[pr] > x) pr--;
        if (pl <= pr) {
            swap(int, a[pl], a[pr]);
            pl++;
            pr--;
            }
    }while(pl <= pr);

        if (left < pr) quick(a, left, pr);
        if (pl < right) quick(a, pl, right);

    }

    int main(void)
    {

    int nx;
    puts("Quick Sort");
    printf("Element's count");
    scanf("%d", &nx);
        int *x = calloc(nx, sizeof (int));
        for (int i = 0; i < nx; i++) {
            printf("x[%d]:  ", i);
            scanf("%d", &x[i]);
        }
        quick(x, 0, nx -1); // 배열 x에 대한 퀵 정렬 실행
        puts("Order by Asscending SORT");

        for (int i =0; i < nx; i++)
            printf("x[%d] = %d\n", i,x[i]);


        free (x);
        return 0;


    } // try1, next is UpGrade_ver2



