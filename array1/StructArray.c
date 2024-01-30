// 구조체 + 베열

#include <stdio.h>
#define VMAX 21 // 시력검사 최대값은 2.1 * 10

typedef struct {

    char name[20]; // 이름
    int height; // 신장
    double weight; // 시력 => 몸무게
} PhysCheck;

// 신장의 평균값 계산
double ave_height(const PhysCheck array[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += array[i].height;

    return sum/n;
}

double ave_weight(const PhysCheck array[], int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += array[i].weight;

    return sum/n;
}


// 시력 분포 계산 함수
/*void dist_vision (const PhysCheck data[], int n, int dist[])
{
    for (int i = 0; i < VMAX; i++)
        dist[i] = 0;
    for (int i = 0; i < n; i++)
        if (data[i].vision >= 0.0 && data[i].vision <= VMAX / 10.0)
            dist[(int)(data[i].vision * 10)]++; } */





int main(void)
{
    PhysCheck x[] = {
            {"윤단희", 158, 52},
            {"고현주", 167, 41 },
            {"오윤아", 154, 44},
            {"이미오", 171, 51},
            {"김도희", 164, 54},
    };
    int nx = sizeof(x) / sizeof (x[0]); // 사람 수
// 배열 'x'의 전체 크기를 바이트 단위로 반환한다.
// 배열 'x'의 첫 번째 요소(구조체)의 크기를 바이트 단위로 반환한다.
// 전체 배열 크기를 첫 번째 요소 크기로 나누면 배열의 요소 수가 된다.
// 배열 'x'에는 5명의 정보가 초기화되고, 변수 'nx'에는 배열의 요소 수가 저장된다.

    puts("  Code :   height  :   weight  ");
    puts("-------------------------------");
    for (int i = 0; i < nx; i++)
        printf("%-18.18s %4d %5.1f\n",  x[i].name,  x[i].height,  x[i].weight);
    printf("\n Average H : %5.1fcm \n", ave_height(x, nx));
    printf("\n Average W : %5.1fkg \n", ave_weight(x, nx));

    return 0;
}
// H: 162.8cm
// W: 48.4kg
