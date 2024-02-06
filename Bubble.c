//ver1
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)
// swap (type...) 사이에 공백 있으면 인식 안됌

void bubble(int a[], int n)
{
    for (int i =0; i < n-1; i++) {
        for (int j = n -1; j > i; j--)
            if (a[j -1] > a[j])   // 중괄호 하나 더 써서 오류
                swap(int, a[j-1], a[j]);


    }
}

int main(void)
{
    int nx;

    puts("Bubble Sorting");
    printf("counting Num : ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }

    bubble(x, nx);

    puts("Sorted by Assending. ");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);

    free(x);
    return 0;

}
