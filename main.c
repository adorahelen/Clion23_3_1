// 다차원 배열

#include <stdio.h>

int mdays[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                   {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
// 각 달의 날 수

int isYear(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
} //윤년 판별 공식

int dayof_year(int y, int m, int d) {
    int days = d; // 날 수
    for (int i = 1; i < m; i++)
        days += mdays[isYear(y)][i - 1]; // 이부분

    return days;
}// 그 해의 지난 날 수를 구하고 더한다.

int main (void)
{
    int retry;
    do {
        int year
    }
}

