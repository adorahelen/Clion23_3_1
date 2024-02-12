#include "PPSheader.h"
#include <stdio.h>

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