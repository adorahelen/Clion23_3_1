#include<stdio.h>
// 진수변환 프로그램
#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)

int conv (unsigned x, int n, char d[])
{
    char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digits = 0;

    if (x == 0)
        d[digits++] =
}
