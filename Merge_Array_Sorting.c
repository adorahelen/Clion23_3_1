// 병합 정렬은 배열을 앞부분과 뒷부분으로 나누어 각각 정렬한 다음 병합한다.
// 1. 정렬을 마친 배열
// 2. 그 배열의 병합을 응용하여, 분할 정복법에 따라 정렬하는 알고리즘
// "각 배열에서 선택한 요소의 값을 비교하여, 작은 값의 요소를 꺼내 새로운 배열에 넣는 작업" (반복)

#include <stdio.h>
#include <stdlib.h>

void merge (const int a[], int na, const int b[], int nb, int c[])
{

    int pa = 0;
    int pb = 0;
    int pc = 0;


    while(pa < na && pb < nb)
        c[pc++] = (a[pa] <= b[pb] ? a[pa++]: b[pb++]);

    while(pa < na)
        c[pc++] = a[pa++];

    while(pb < nb)
        c[pc++] = b[pb++];
}

int main(void)
{
    int na, nb;
    printf("A elemental Count is? : ");
    scanf("%d", &na);

    printf("B elemental Count is? : ");
    scanf("%d", &nb);

    int *a = calloc(na, sizeof (int));
    int *b = calloc(na, sizeof (int));
    int *c = calloc(na + nb, sizeof (int));
// 기본


    printf("a[0] : ");
    scanf("%d", &a[0]);
    for(int i = 1; i < na; i++){
        do {
            printf("a[%d]: ", i);
            scanf("%d", &a[i]);
        } while(a[i] < a[i - 1]);
    }

    printf("b[0] : ");
    scanf("%d", &b[0]);
    for(int i = 1; i < nb; i++){
        do {
            printf("b[%d]: ", i);
            scanf("%d", &b[i]);
        } while(b[i] < b[i - 1]);
    }

    // 배열 a와 b를 병합하여 c에 저장 후, 출력

    merge(a, na, b, nb, c);
    puts("Array A and B merged and saved Array C. ");
    for (int i = 0; i < na + nb; i++)
        printf("c[%2d]  =  %2d\n", i, c[i]);

    free(a);
    free(b);
    free(c);

    return 0;
}