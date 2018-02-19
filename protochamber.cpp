/*********************************************************************
** Program: Final Project
** File: protochamber.cpp
** Author: Charles Jadin
** Date: March 21, 2017
** Description: Function implementations for the ProtoChamber class,
**  derived from the Space class.
*********************************************************************/

#include <iostream>
#include <string>
#include "protochamber.hpp"
using std::cout;
using std::cin;
using std::string;

/*********************************************************************
** Constructor; sets null pointers and initializes variables
*********************************************************************/
ProtoChamber::ProtoChamber()
{
    north = NULL;
    east = NULL;
    south = NULL;
    west = NULL;
    currentGame = NULL;
    imgName = "pcimage";
    scptName = "pcscript";
    searched = false;
    taskComplete = false;
    objective = "Examine the robot";
}

/*********************************************************************
** Destructor; sets all pointers to null
*********************************************************************/
ProtoChamber::~ProtoChamber()
{
    north = NULL;
    east = NULL;
    south = NULL;
    west = NULL;
}

/*********************************************************************
** Sets the currentGame pointer to a passed variable
*********************************************************************/
void ProtoChamber::setGamePoint(Game * cg)
{
    currentGame = cg;
}

/*********************************************************************
** Effect of using the power cell in this room
*********************************************************************/
int ProtoChamber::itemEffect()
{
    cout << "\nYou've powered up the old robot! \nTL7-X:  What is ";
    cout << "your command? \nDR:  Protect this lab from intruders.\n";
    cout << "\nThe robot obeys and is guarding the front door.\n";

    (*currentGame).reduceThreat(5);

    taskComplete = true;

    return 0;
}

/*********************************************************************
** Effect of interacting with this room.
*********************************************************************/
int ProtoChamber::interact()
{
    cout << "\nIt's a TL7-X, one of your old models.  It isn't linked";
    cout << " to the other robots' AI grid, \nso you may be able to ";
    cout << "use it to your advantage.  But it needs a power source.\n";

    if (taskComplete)
    {
        searched = true;
    }

    return 0;
}


