/*********************************************************************
** Program: Final Project
** File: fpMain.cpp
** Author: Charles Jadin
** Date: March 21, 2017
** Description: Main method for the game (Game object is called
**  robotUprising, but it's kind of a working title)
*********************************************************************/

#include <iostream>
#include "game.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(0));

    Game robotUprising;

    robotUprising.runGame();

    return 0;
}


