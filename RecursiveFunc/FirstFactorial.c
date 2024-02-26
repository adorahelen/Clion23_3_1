// 슨차곱셈 구하기
// 순차곱셈의 결과를 재귀적으로 구하여 출력하는 코드

#include <stdio.h>
int factorial (int n)
{
    if(n > 0)
        return n * factorial(n - 1);
    else
        return 1;
} // == return (n > 0) ? n * factorial(n-1) : 1;
// 재귀 호출은 '함수 자신'을 호출한다고 이해하기보디는 '자기 자신과 똑같은 함수'를 호출한다고 이해
int main(void)
{
    int x;
    printf("Enter the NUM : ");
    scanf("%d", &x);
    printf("%d 's Sequential Multiply is %d . \n", x, factorial(x));

    return 0;
}