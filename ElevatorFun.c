//
// Created by adora on 2024-02-14.
//
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "ElevatorHeader.h"
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
void terminate (ELEVATOR* elev);
void move (ELEVATOR* elev);
void anyUpRequest (ELEVATOR* elev);
void anyDownRequest (ELEVATOR* elev);
void moveUp (ELEVATOR* elev);
void moveDown (ELEVATOR* elev);
void timePass (int m);