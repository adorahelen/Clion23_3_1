// < 단순 선택 정렬 >
// 아직 정렬하지 않은 부분에서 가장 작은 키의 값 a(min)을 선택한다.
// a(min)과 아직 정렬하지 않은 부분의 첫 번째 요소를 교환한다.
// 위와 같은 과정을 n-1 회  반복한다.


/*void SimpleSelection (int a[], int n)
{
    for(int i =0; i < n-1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap(int, a[j], a[min]);

    }
}*/

// <단순 삽입 정렬>
// 선택한 요소를 그보다 더 앞쪽의 알맞은 위치에 '삽입하는' 작업을 반복하여 정렬하는 알고리즘

#include <stdio.h>
#include <stdlib.h>

void Insertion (int a[], int n)
{ // 정렬된 부분과 아직 정렬되지 않은 부분에서 배열이 다시 구성된다.
    for (int i = 1; i < n; i++) {
        int tmp = a[i];
        int j;
        for(j = i; j>0 && a[j-1] > tmp; j--)
            a[j] = a[j - 1];
        a[j] = tmp;

            // 정렬된 왼쪽 끝에 도달
            // tmp보다 작거나 같은 key를 갖는 항복 a[j-1]발견
    }
}
// 어제 공부한 버블정렬, 오늘 공부한 선택&삽입 정렬의 시간 복잡도는 모두 O(n^2);

int main(void)
{
    int nx;
    puts("Simple Insert Selection");
    printf("Num of atom : ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof (int));

    for(int i=0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }

    Insertion(x, nx);; // 배열 + 사이즈

    puts("Is it Assending Sort");
    for(int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);



    free(x);
    return 0;
}