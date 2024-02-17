//
// Created by adora on 2024-02-14.
//



#include "ElevatorHeader.h" // 여기서는 헤더를 포함했으니 ㄱㅊ
#define TOP_FLOOR 10
#define DELAY_FACTOR 10000

void initialize (ELEVATOR* elev) {
    elev-> buttons = calloc(TOP_FLOOR + 1,
                            sizeof (BUTTON_STATUS));
    for (int i = 0; i <= TOP_FLOOR; i++)
        elev->buttons[i] = OUT;
    elev->currentFloor = 1;

    return;
}

void runElevator (ELEVATOR* elev){
    char buffer[81];
    int floor;
    char* pStrIn;

    printf("\n\n This elevator goes from basement (0) ");
    printf("to floor %d", TOP_FLOOR);
    printf("\n\n Type floors & press return to start");
    printf("\n If no new floors, press return key. ");
    printf("\n To quit, key EOF ");
    printf("\n\n Please enter floors: ");

    while (fgets(buffer, 81, stdin))
    {
        pStrIn = buffer;
        while (*pStrIn != '\n')
        {
            // Locate next floor digit & convert to int
            while (*pStrIn == ' ')
                pStrIn++;
            if (!isdigit(*pStrIn))
            {
                printf("\a Invalid floor %c\n", *pStrIn);
                pStrIn++;
            }
            else
            {
                sscanf(pStrIn, "%d", &floor);
                if (floor == elev->currentFloor)
                    printf("\n\a Already on floor %d. ",
                           elev->currentFloor);
                else
                    if (floor < 0 || floor > TOP_FLOOR)
                        printf("\n\a %d invalid floor",
                               floor);
                    else
                        elev->buttons[floor] = IN;

                // Synchronize sscanf + *pStrIn
                while (isdigit(*pStrIn))
                    pStrIn++;
            } // else
        } // while

        move(elev);
        printf("\n\n Please enter floors: ");
    } // while
    return;
} // end of func : runEleve

void move (ELEVATOR* elev) {
    static DIRECTION_STATUS direction = STOP;
    // Local Dec
    bool anyUp;
    bool anyDown;
    // Statements
    anyUp = anyUpRequest(elev);
    anyDown = anyDownRequest(elev);

    if (direction == UP)
    {
        if (!anyUp && anyDown)
            direction = DOWN;
        else
            if (!anyUp && anyDown)
                direction = STOP;
    } // 올라감

    else if (direction == DOWN)
    {
        if (!anyDown && anyUp)
            direction = UP;
        else
            if (!anyDown && !anyUp)
                direction = STOP;
    } // 내려감

    else if (direction == STOP)
    {
        if (anyUp)
            direction = UP;
        else
            if (anyDown)
                direction = DOWN;
    } // 위, 아래, 멈춤 버튼

    if (direction == UP)
        moveUp(elev);
    else
        if (direction == DOWN)
            moveDown(elev);
        else
            printf("\n**** NO BUTTON PRESSED **** ");
    return;
    // move method



}

void moveUp (ELEVATOR* elev)
{
// statements
    printf("\n The door is being closed ...");
    printf("\n We are going up.");
    (elev->currentFloor)++;
    while (elev->buttons[elev->currentFloor] != IN)
    {
        printf("\n");
        timePass(2);
        printf("\n Passing floor %d", elev->currentFloor);
        printf("\n");
        timePass(2);
        (elev->currentFloor)++;
    } // while

    elev->buttons[elev->currentFloor] = OUT;
    printf("\nThe door is being opened...");
    printf("\n");
    printf("\n **** FLOOR %d ****",
           elev->currentFloor);
    printf("\n");
    timePass(4);
    return;
} // moveUp

void moveDown (ELEVATOR* elev){
    printf("\nThe door is being closed ...");
    printf("\nWe are going down");
    (elev->currentFloor)--;
    while (elev->buttons [elev->currentFloor] != IN)
    {
        printf("\n");
        timePass(2);
        printf("\nPassing floor %d", elev->currentFloor);
        printf("\n");
        timePass(2);
        (elev->currentFloor)--;
    } // while
    elev->buttons [elev->currentFloor] = OUT;
    printf("\n The door is being opend ...");
    printf("\n");
    printf("\n **** FLOOR %d **** ",
           elev->currentFloor);
    printf("\n");
    timePass(4);

    return;
} // moveDown

bool anyUpRequest (ELEVATOR* elev) {
    // This func checks to see if any request is for a floor above the cf.
    /* 엘리베이터가 현재 층보다 높은 층에 요청이 있는지를 확인하는 함수이다.
     * 함수의 반환값은 bool 타입으로 true, false를 반환한다.
     * 매개변수로는 Elevator포인터인 elev가 전달된다.
     * 함수 내에서 isAny 변수를 선언하고, false로 초기화한다.
     * (이 변수는 현재 층보다 높은 층에 요청이 있는지를 나타낸다. )
     *for 루프를 사용해 현재 층부터 가장 높은층 [TOP Floor]까지 반복한다.
     * 이떄, isAny가 true이거나 가장 높은 층에 도달할때까지 반복한다.
     * elev->buttons[check] == IN을 통해 해당 층에 버튼이 눌려있는지 여부를 확인하고,
     * 이 값을 isAny에 대입/ True면 현재 층보다 높은 층에 요청이 있음& false면 아님
     * */

    // Local
    bool isAny = false;

    // statements
    for (int check= elev->currentFloor;
    check <=TOP_FLOOR && !isAny;
    check++)
        isAny = (elev->buttons[check] == IN);

    return isAny;
}
bool anyDownRequest (ELEVATOR* elev)
{
    //Local Decl
    bool isAny = false;

    // Statements
    for (int check = elev->currentFloor;
    check >= 0;
    check--)
        isAny = isAny || (elev->buttons[check] == IN);
    return isAny;
}
void timePass (int time){
    // statements
    for (long  i = 0; i < (time* DELAY_FACTOR); i++);
    return;
}
void terminate (ELEVATOR* elev) {
    free(elev->buttons);
    return;
}
// end