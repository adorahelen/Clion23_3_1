//
// Created by adora on 2024-02-11.
//

#ifndef CLION23_3_1_HEADER_H
#define CLION23_3_1_HEADER_H

// Global Type
typedef struct
{
    char name[26];
    int midterm[3];
    int final;
} STUDENT; // 구조체 설정

void InserSort (STUDENT list[], int last); // 구조체 배열을 사용할 것

#endif //CLION23_3_1_HEADER_H
