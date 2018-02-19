/*********************************************************************
** Program: Final Project
** File: supplyroom.cpp
** Author: Charles Jadin
** Date: March 21, 2017
** Description: Function implementations for the SupplyRoom class,
**  derived from the Space class.
*********************************************************************/

#include <iostream>
#include <string>
#include "supplyroom.hpp"
using std::cout;
using std::cin;
using std::string;

/*********************************************************************
** Constructor; sets null pointers and initializes variables
*********************************************************************/
SupplyRoom::SupplyRoom()
{
    north = NULL;
    east = NULL;
    south = NULL;
    west = NULL;
    imgName = "srimage";
    scptName = "srscript";
    searched = false;
    taskComplete = true;
    objective = "";
}

/*********************************************************************
** Destructor; sets all pointers to null
*********************************************************************/
SupplyRoom::~SupplyRoom()
{
    north = NULL;
    east = NULL;
    south = NULL;
    west = NULL;
}

/*********************************************************************
** No item effect for this room
*********************************************************************/
int SupplyRoom::itemEffect()
{
    return 0;
}

/*********************************************************************
** No interaction effect for this room
*********************************************************************/
int SupplyRoom::interact()
{
    return 0;
}

