/*********************************************************************
** Program: Final Project
** File: workarea.cpp
** Author: Charles Jadin
** Date: March 21, 2017
** Description: Function implementations for the WorkArea class,
**  derived from the Space class.
*********************************************************************/

#include <iostream>
#include <string>
#include "workarea.hpp"
using std::cout;
using std::cin;
using std::string;

/*********************************************************************
** Constructor; sets null pointers and initializes variables
*********************************************************************/
WorkArea::WorkArea()
{
    north = NULL;
    east = NULL;
    south = NULL;
    west = NULL;
    imgName = "waimage";
    scptName = "wascript";
    searched = false;
    taskComplete = false;
    objective = "Examine the computer.";
}

/*********************************************************************
** Destructor; sets all pointers to null
*********************************************************************/
WorkArea::~WorkArea()
{
    north = NULL;
    east = NULL;
    south = NULL;
    west = NULL;
}

/*********************************************************************
** Sets a pointer to an item (the infinite loop device), which drops
**  after interaction with the computer
*********************************************************************/
void WorkArea::setQitem(Item * ld)
{
    loopDev = *ld;
}

/*********************************************************************
** No item effect for this room.
*********************************************************************/
int WorkArea::itemEffect()
{
    return 0;
}

/*********************************************************************
** Effect of interacting with this room.
*********************************************************************/
int WorkArea::interact()
{
    cout << "\nWith some quick work, you've downloaded the infinite";
    cout << " loop code and installed it on \na device with near-field";
    cout << " connectivity functionality.  Just make sure you pick \n";
    cout << "it up before you leave the room.\n";

    dropItem(&loopDev);

    taskComplete = true;

    return 0;
}