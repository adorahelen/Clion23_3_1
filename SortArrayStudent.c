//
// Created by adora on 2024-02-10.
// Did you know? In SoGangUni, Can go Kanegi melon Uni!

#include <stdio.h>
#include <stralign.h>
#include <stdbool.h>

#define NUM_STU 5

// Global Type
    typedef struct
    {
    char name[26];
    int midterm[3];
    int final;
    } STUDENT; // 구조체 설정

// Function
void InserSort (STUDENT list[], int last); // 구조체 배열을 사용할 것

int main(void)
{
    // Local
    STUDENT stuAry[NUM_STU] = // 구조체 배열
            {
                    {"DanHe, HyeonJU",  {85, 94, 79}, 93},
                    {"YunNa, Mioo",     {75, 91, 89}, 89},
                    {"NoRiKo, DoHee",   {87, 88, 89}, 90},
                    {"SungJo, HanhHee", {78, 96, 88}, 91},
                    {"HyooJin, YuuKi",     {83, 79, 93}, 91}
            }; // setArray ()

    printf("Unsorted Data List: \n");
    for (STUDENT* pStuptr = stuAry;
        pStuptr < stuAry + NUM_STU; // 더하는거 배열의 개수 처음에 define한
        pStuptr++) {

        printf("%-26s %4d %4d %4d %4d \n",
               pStuptr->name,
               pStuptr->midterm[0],
               pStuptr->midterm[1],
               pStuptr->midterm[2],
               pStuptr->final); }

    printf("\n");

    InserSort(stuAry,NUM_STU-1); // 삽입정렬 실행

    printf("Sorted data: \n");
    for (STUDENT* pStuptr = stuAry;
         pStuptr < stuAry + NUM_STU; // 더하는거 배열의 개수 처음에 define한
         pStuptr++) {

        printf("%-26s %4d %4d %4d %4d \n",
               pStuptr->name,
               pStuptr->midterm[0],
               pStuptr->midterm[1],
               pStuptr->midterm[2],
               pStuptr->final); }

    return 0;
    // main 끝
}
