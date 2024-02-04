#include <stdio.h>
#include "Queue.h"

int main (void) {
    IntQueue que;

    if (Initial(&que, 64) == -1) {
        puts("You failed created QUE ");
        return 1;
    }
    while(1) {
        int m, x;

        printf("Current Data : %d / %d \n", Size(&que), Capacity(&que)); // 현재 0/64 용량
        printf("1 InQue, 2 DeQue, 3 Peek, 4 show, 0 Exit ");
        scanf("%d", &m);

        if (m == 0) break;
        switch(m) {
            case 1:
                printf("Data: ");
                scanf("%d", &x);
                if (inQue(&que, x) == -1)
                    puts("\a Error: inQue is Failed");
                break;

            case 2:
                if(outQue(&que, &x) == -1)
                    puts("\a Error: Deque is Failed");
                else
                    printf("Deque Data is %d ", x);
                break;

            case 3:
                if (Peek(&que, &x) == -1)
                    puts("\a Error: Peek Faile");
                else
                    printf("Peeked Data is %d", x);
                break;

            case 4:
                Print(&que);
                break;
        }

    }
    Terminate(&que);
    return 0;

}