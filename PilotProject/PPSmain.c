#include <stdio.h>
#include "PPSheader.h"
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
/* <Sending The Whole Structure>
 Divided form Only main to Header/Function/main;
*/