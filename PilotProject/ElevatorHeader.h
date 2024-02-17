//
// Created by adora on 2024-02-14.
//

#ifndef CLION23_3_1_ELEVATORHEADER_H
#define CLION23_3_1_ELEVATORHEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h> // 왜 Fun.c가 아니라 여기에 넣어야 하는 걸까?
// 불리안은 정의되어 있지 않다고 함

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
bool anyUpRequest (ELEVATOR* elev);
bool anyDownRequest (ELEVATOR* elev);
void moveUp (ELEVATOR* elev);
void moveDown (ELEVATOR* elev);
void timePass (int m);

#endif //CLION23_3_1_ELEVATORHEADER_H
