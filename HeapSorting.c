#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)

static void downHeap (int a[], int left, int right);
void heapSort (int a[], int n);

int main(void) {

    int nx;
    puts(" This is Heap Sorting ");
    printf(" Elemental Counting : ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof (int));

    for(int i = 0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }
    heapSort(x, nx); // 배열 x를 힙 정렬
    puts("Sorted by Asscending");
    for (int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);
    return 0;
}
static void downHeap (int a[], int left, int right){
    int temp = a[left]; // 루트 노드
    int child;
    int parent;

    for(parent = left; parent < (right + 1) / 2; parent = child) {
        int cl = parent * 2 + 1; // 왼쪽 자식
        int cr = cl + 1;  // 오른쪽 자식
        child = ( cr <= right && a[cr] > a[cl]) ? cr: cl; // 큰 값을 선택
        if (temp >= a[child])
            break;

        a[parent] = a[child];
    }
    a[parent] = temp;
}
void heapSort (int a[], int n){

    // 1. 배열 a를 힙으로 만든다.
    // 2. 루트에 있는 가장 큰 값을 빼내어 배열 마지막 요소와 바꾸고
    // 배열의 나머지 부분을 다시 힙으로 만드는 과정을 반복, 정렬 수행

    for(int i = (n-1) / 2; i >= 0; i--)
        downHeap(a, i, n-1);

    for (int i = n - 1; i > 0; i--) {
        swap(int, a[0], a[i]);
        downHeap(a, 0, i -1);
    }

}
