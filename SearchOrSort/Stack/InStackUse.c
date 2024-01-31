#include <stdio.h>
#include "InStack.h"

int main (void)
{
    IntStack s; // Instack structer Call 's';
    if (Initialize(&s, 64) == -1) {
        puts("You Failed make the Stack");
        return 1;
    }

    while(1) {
        int menu, x;
        printf("Current Data : %d  /  %d\n", Size(&s), Capacity(&s));
        printf("1. PUSH  2. POP  3. PEEK  4. Print  5. END");
        scanf("%d", &menu);

        if(menu == 0) break;
        switch(menu) {
            case 1:
                printf("DATA : ");
                scanf("%d", &x);
                if (Push(&s, x) == -1)
                    puts("\a ERROR: We Failed PUSH ...");
                else
                    printf("this data %d is enter\n", x);
                break;
                /* 따로 푸쉬를 사용하지 않아도 여기서 if문을 무조건 실행하며 데이터가 푸쉬되는 거 같음 */

            case 2:
                if (Pop(&s, &x) == -1)
                    puts("\a ERROR: We Failed POP ...");
                else
                    printf("this data %d is Del\n", x);
                break;

            case 3:
                if (Peek(&s, &x) == -1)
                    puts("\a ERROR: we Failed peek ...");
                else
                    printf("Peek (TOP) data is %d\n", x);
                break;

            case 4:
                Print(&s);
                break;
        } // switch end
    } // while end
    Terminate(&s);
    return 0;
    }
    