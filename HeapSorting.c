#include <stdio.h>
#include <stdlib.h>

#define swap (type, x, y) do {type t = x; x = y; y = t;} while (0)

static void downHeap (int a[], int left, int right);
void heapSort (int a[], int n);

int main(void) {

    int nx;
    puts(" This is Heap Sorting ");
    printf(" Elemental Counting : ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof (int));

}