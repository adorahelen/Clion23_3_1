// Created by adora on 2024-02-12.
// Ending is 828p, This is 804;
// <Sending The Whole Structure>

#include <stdio.h>

typedef struct
{
    int numerator; // 분자
    int denominator; // 분모
} FRACTION; // 분수

// Function Decl
FRACTION getFr (void); // 자료형(구조체)_함수 이름()_원소 값(미정)
FRACTION  multFr (FRACTION fr1, FRACTION fr2);
void printFr (FRACTION fr1, FRACTION fr2, FRACTION result);


int main(void) {

    // Local
    FRACTION fr1;
    FRACTION fr2;
    FRACTION res;

    // Statements
    fr1 = getFr();
    fr2 = getFr();
    res = multFr(fr1,fr2);
    printFr(fr1, fr2, res);
    return 0;
}

FRACTION getFr(void)
{
    // Local
    FRACTION fr;

    printf("Write a fraction in the form of x/y: ");
    scanf("%d/%d", &fr.numerator, &fr.denominator);
    return fr;
}

FRACTION multFr(FRACTION fr1, FRACTION fr2)
{
    // Local
    FRACTION res;

    // Statements
    res.numerator = fr1.numerator * fr2.numerator;
    res.denominator = fr1.denominator * fr2.denominator;
    return res;
}

void printFr(FRACTION fr1, FRACTION fr2, FRACTION res)
{
    // Statements
    printf("\n The result of %d/%d * %d/%d is %d/%d\n",
           fr1.numerator, fr1.denominator,
           fr2.numerator, fr2.denominator,
           res.numerator, res.denominator);
    return;
}