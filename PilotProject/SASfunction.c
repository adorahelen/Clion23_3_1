//
// Created by adora on 2024-02-11.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "SASheader.h"

void InserSort(STUDENT list[], int last) {

// Local
    bool located;
    STUDENT temp;
    STUDENT *pCurrent;
    STUDENT *pWalker;
    STUDENT *pLast;

// Statements
    for (pCurrent = list + 1, pLast = list + last;
         pCurrent <= pLast;
         pCurrent++)
    {
        located = false;
        temp = *pCurrent;

        for (pWalker = pCurrent - 1;
            pWalker >= list && !located;
        ) //????
            if (strcmp(temp.name, pWalker->name) < 0)
            {
                *(pWalker + 1) = *pWalker;
                pWalker--;
            }
            else
                located = true;
            *(pWalker + 1) = temp;
    }
    return;
}

