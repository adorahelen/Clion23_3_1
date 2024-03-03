#include <stdio.h>
#include <stdlib.h>

static int *buff; // 작업용 배열 선언

// 병합용 정렬 main
static void __mergesort (int a[], int left, int right)
{
    if (left < right) {
        int center =(left + right) / 2;
        int p =0;
        int i;
        int j = 0;
        int k = left;
        __mergesort(a, left, center); // front 병합 정렬
        __mergesort(a, center + 1, right); // back 병합 정렬
        /*
         * 1. 함수를 정의하는 도중에 스스로를 호출 할 수 있다.
         * 2. 이코드는 재귀 함수 이다.
         * = 병합 정렬은 "분할 정복"알고리즘의 한 예로, 리스트를 두 부분으로 분할하고
         * 각각을 정렬한 다음 병합하는 과정을 반복하여 정렬한다.
         * 재귀 호출을 사용하여 리스트를 계속해서 분할하고 정렬하는데.
         * 여기서는 '__mergesort' 함수가 자기 자신을 호출하여 리스트를 분할하고 정렬한다.
         * */
        for (i = left; i <= center; i++) // 정렬된 리스트를 병합하는 과정
            buff[p++] = a[i];
        while (i <= right && j < p)
            a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
        while(j < p)
            a[k++] = buff[j++];
    }
}

int mergesort (int a[], int n) {
    if ((buff = calloc(n, sizeof (int)))  == NULL)
        return -1;
    __mergesort(a, 0, n-1);

    free(buff);
    return 0;
}

int main (void) {

    int nx;
    puts(" Merge Sorting");
    printf(" Numbers of elemental : ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    for (int i = 0; i < nx; i++) {
        printf(" x[%d]: ", i);
        scanf("%d", &x[i]);

    }

    mergesort(x, nx);
    puts("Sorted by Assending . ");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n ", i, x[i]);
    free(x);

    return 0;
}

