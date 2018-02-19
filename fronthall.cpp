/*********************************************************************
** Program: Final Project
** File: fronthall.cpp
** Author: Charles Jadin
** Date: March 21, 2017
** Description: Function implementations for the FrontHall class,
**  derived from the Space class.
*********************************************************************/

#include <iostream>
#include <string>
#include "fronthall.hpp"
using std::cout;
using std::cin;
using std::string;

/*********************************************************************
** Constructor; sets null pointers and initializes variables
*********************************************************************/
FrontHall::FrontHall()
{
    north = NULL;
    east = NULL;
    south = NULL;
    west = NULL;
    terminal = NULL;
    imgName = "fhimage";
    scptName = "fhscript";
    searched = false;
    taskComplete = false;
    objective = "Bar the front door";
}

/*********************************************************************
** Destructor; sets all pointers to null
*********************************************************************/
FrontHall::~FrontHall()
{
    north = NULL;
    east = NULL;
    south = NULL;
    west = NULL;
    terminal = NULL;
}

/*********************************************************************
** Sets the pointer to the terminal room, which is locked until the
**  key card is used
*********************************************************************/
void FrontHall::pointToLocked(Space * l)
{
    terminal = l;
}

/*********************************************************************
** Effect of using the key card in this room
*********************************************************************/
int FrontHall::itemEffect()
{
    cout << "\nThe main terminal room is now unlocked!\n";
    east = terminal;

    return 0;
}

/*********************************************************************
** Effect of interacting with this room.
*********************************************************************/
int FrontHall::interact()
{
    cout << "\nYou've barred the door.  It should buy a little bit";
    cout << " of time before they inevitably break through.\n";
    taskComplete = true;

    return 4;
}


