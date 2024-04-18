#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 4 // 행과 열에 최대값

double det(double (*A) [N], int n); // 행렬식을 구하는 자기호출 함수

void main() {

    int i = 0, j = 0;
    int n;
    double A[N][N] = {0,}; // 입력받을 행렬의 2차원 배열


    scanf("%d", &n); // 행렬의 크기 입력

    // 각각의 행렬 값 입력
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }

    // 입력한 행렬 값 출력
    for (i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%.f\t", A[i][j]);
        }
        printf("|\n");
    }
    printf("\n");

    // 행렬식 값을 출력
    printf("입력한 행렬의 행렬식 값\n");
    printf(" Det(A) = %.f\n\n", det(A,n));

}

double det(double (*A) [N], int n)
{
    int i,j,k,y; // 루프를 저장 하기 위한 변수 선언
    double det_a = 0; // 결과 값 저장 변수
    double temp[N][N]; // 행렬식 값 임시 저장 배열


    // 알고리즘
    if (n != 1)
    {
        for (i = 0; i < n; i++)
        {
            for(j = 1; j < n; j++)
            {
                y = 0;

                for(k = 0; k < n; k++)
                {
                    if(k != i)
                    {
                        temp[j-1][y++] = *(A[0]+j*N+k);
                        // 소행렬식을 구하기 위해 각 행렬의 원소들을 재배치한다.
                    }
                }
            }
            det_a = det_a + *(A[0]+i) * (pow(-1,i)) * det(temp,n-1);
            // 소행렬식들의 전체 합을 구한다.
        }
        return det_a;
    }
    else {
       return *A[0];
    }
}

