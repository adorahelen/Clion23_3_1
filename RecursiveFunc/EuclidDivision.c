// 유클리드 호제법에 의해 최대공약수를 구하여 출력

#include <stdio.h>

int gcd(int x, int y)
{
    if(y == 0)
        return x;
    else
        return gcd(y,x % y);
}

int main(void)
{
    int x, y;
    puts("We Find \"\The Greatest common divisor.\"\ ");
    printf("Enter the Integer : ");
    scanf("%d", &x);
    printf("Enter the Integer : ");
    scanf("%d", &y);
    printf("The Greatest common divisor is %d .\n", gcd(x,y));

    return 0;
}