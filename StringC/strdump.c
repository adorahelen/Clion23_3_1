//
// Created by adora on 2024-03-05.
//
// STRING 을 구성하는 모든 문자의 값을 16진수와 2진수로 출력
#include <stdio.h>
#include <limits.h>

void str_dump (const char *s)
{
    do {
        int i;
        printf("%c %0*X ", *s, (CHAR_BIT + 3) / 4, *s);
        for(i = CHAR_BIT -1; i >= 0; i--)
            putchar(((*s >> i ) & 1U) ? '1' : '0');
        putchar('\n');
    } while(*s++ != '\0');
}

int main (void)
{
    str_dump("STRING");
    return 0;
}