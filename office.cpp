/*********************************************************************
** Program: Final Project
** File: office.cpp
** Author: Charles Jadin
** Date: March 21, 2017
** Description: Function implementations for the Office class,
**  derived from the Space class.
*********************************************************************/

#include <iostream>
#include <string>
#include "office.hpp"
using std::cout;
using std::cin;
using std::string;

/*********************************************************************
** Constructor; sets null pointers and initializes values
*********************************************************************/
Office::Office()
{
    north = NULL;
    east = NULL;
    south = NULL;
    west = NULL;
    front = NULL;
    imgName = "ofimage";
    scptName = "ofscript";
    searched = false;
    taskComplete = false;
    objective = "Unlock the door to the front hall";
}

/*********************************************************************
** Destructor; sets pointers to null
*********************************************************************/
Office::~Office()
{
    north = NULL;
    east = NULL;
    south = NULL;
    west = NULL;
}

/*********************************************************************
** Sets the front pointer; points to the front hall, which is locked
**  before interacting with the room
*********************************************************************/
void Office::pointToLocked(Space * l)
{
    front = l;
}

/*********************************************************************
** There is no item effect for this room
*********************************************************************/
int Office::itemEffect()
{
    return 0;
}

/*********************************************************************
** Effect of interacting with this room.
*********************************************************************/
int Office::interact()
{
    cout << "\nYou've unlocked the door to the front hall.\n";
    south = front;
    front->connect('n', this);
    taskComplete = true;

    return 0;
}
