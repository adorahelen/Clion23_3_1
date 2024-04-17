#include <stdio.h>

#define MAX 30

int main(void) {

    int i, j;
    int n = 0;
    int m = 0;
    int vMatrixA[MAX] [MAX] = {0,};
    int vMatrixB[MAX] [MAX] = {0,};
    int vResult[MAX] [MAX] = {0,};

    scanf("%d", &n); // 행
    scanf("%d", &m); // 열

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &vMatrixA[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &vMatrixB[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            vResult[i][j] += vMatrixA[i][j] + vMatrixB[i][j];
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%4d ", vResult[i][j]);
        }

        printf("\n");
    }

    printf("\n");

    return 0;
}