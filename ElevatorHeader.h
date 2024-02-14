//
// Created by adora on 2024-02-14.
//

#ifndef CLION23_3_1_ELEVATORHEADER_H
#define CLION23_3_1_ELEVATORHEADER_H

// Global Tpye
typedef enum {OUT, IN} BUTTON_STATUS;
typedef enum {DOWN, STOP, UP} DIRECTION_STATUS;
typedef struct
{
    int currentFloor;
    BUTTON_STATUS* buttons;

} ELEVATOR;


void initialize (ELEVATOR* elev);
void runElevator (ELEVATOR* elev);
void terminate (ELEVATOR* elev);
void move (ELEVATOR* elev);
void anyUpRequest (ELEVATOR* elev);
void anyDownRequest (ELEVATOR* elev);
void moveUp (ELEVATOR* elev);
void moveDown (ELEVATOR* elev);
void timePass (int m);

#endif //CLION23_3_1_ELEVATORHEADER_H
