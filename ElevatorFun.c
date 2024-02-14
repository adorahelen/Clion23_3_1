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

void initialize (ELEVATOR* elev);
void runElevator (ELEVATOR* elev);
void terminate (ELEVATOR* elev);
void move (ELEVATOR* elev);
void anyUpRequest (ELEVATOR* elev);
void anyDownRequest (ELEVATOR* elev);
void moveUp (ELEVATOR* elev);
void moveDown (ELEVATOR* elev);
void timePass (int m);