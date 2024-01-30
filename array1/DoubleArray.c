// 다차원 배열

#include <stdio.h>

int mdays[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                   {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
// 각 달의 날 수

int isYear(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
} //윤년 판별 공식 (윤년이면 1, 평년이면 0을 반환한다.)

int dayof_year(int y, int m, int d) {
    int days = d; // 날 수
    for (int i = 1; i < m; i++)
        days += mdays[isYear(y)][i - 1]; // 이부분
    // isYear()을 호출하여 0||1을 반환
    // 해당하는 년에 맞게 이전 월의 일 수들을 더한다.

    return days;
}// 지난 날 들의 합

int main (void)
{
    int retry;
    do {
        int year, month, day;
        printf("year : ");
        scanf("%d", &year);

        printf("month : ");
        scanf("%d", &month);

        printf("Days : ");
        scanf("%d", &day);

        printf("%d years %d days. \n", year, dayof_year(year, month, day));
        printf(" retry ? (if you wanna Yes enter 1 else 0)");
        scanf("%d", &retry);
    } while(retry == 1);

    return 0;
}

