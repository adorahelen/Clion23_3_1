// 슨차곱셈 구하기
// 순차곱셈의 결과를 재귀적으로 구하여 출력하는 코드

#include <stdio.h>
int factorial (int n)
{
    if(n > 0)
        return n * factorial(n - 1);
    else
        return 1;
}
int main(void)
{
    int x;
    printf("Enter the NUM : ");
    scanf("%d", &x);
    printf("%d 's Sequential Multiply is %d . \n", x, factorial(x));

    return 0;
}