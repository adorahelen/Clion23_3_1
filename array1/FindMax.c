#include <stdio.h>
#include <stdlib.h>

int maxof (const int a[], int n);

int main (void)
{
    int number;
    printf("Enter the count : ");
    scanf("%d", &number);
    int *height = calloc(number, sizeof(int));
    printf("%d number of enter the height \n", number);

    for (int i = 0; i < number; i++) {
        printf("%d : ", i);
        scanf("%d", &height[i]); // 배열에 원소 입력시 & 뺴먹지 말 것
    }
    printf("The maximum of height is  %d ", maxof(height, number));
    free(height);
    return 0;
}

int maxof (const int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max) max = a[i];
    return max;
}

