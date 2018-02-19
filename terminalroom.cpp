/*********************************************************************
** Program: Final Project
** File: terminalroom.cpp
** Author: Charles Jadin
** Date: March 21, 2017
** Description: Function implementations for the TerminalRoom class,
**  derived from the Space class.
*********************************************************************/

#include <iostream>
#include <string>
#include "terminalroom.hpp"
using std::cout;
using std::cin;
using std::string;

/*********************************************************************
** Constructor; sets null pointers and initializes variables
*********************************************************************/
TerminalRoom::TerminalRoom()
{
    north = NULL;
    east = NULL;
    south = NULL;
    west = NULL;
    imgName = "trimage";
    scptName = "trscript";
    searched = false;
    taskComplete = false;
    objective = "Access the main computer terminal";
}

/*********************************************************************
** Destructor; sets all pointers to null
*********************************************************************/
TerminalRoom::~TerminalRoom()
{
    north = NULL;
    east = NULL;
    south = NULL;
    west = NULL;
}

/*********************************************************************
** No item effect for this room
*********************************************************************/
int TerminalRoom::itemEffect()
{
    return 0;
}

/*********************************************************************
** Effect of interacting with this room.  Ends the game.
*********************************************************************/
int TerminalRoom::interact()
{
    char c = 'Z';
    while (c != '1' && c != '2')
    {
        cout << "\nWhat would you like to do?\n";
        cout << "\n[1] Initiate Omega Protocol \n[2] Play Skyrim \n";
        std::cin.ignore(1, '\n');
        std::cin.clear();
        c = std::cin.get();
    }

    if (c == '2')
    {
        cout << "\nAgainst your better judgment, you fire up your ";
        cout << "favorite game.  This might \nget you killed, and maybe";
        cout << " a lot of other people, but it's totally worth it.\n";
        
        return -1;
    }

    else
    {
        cout << "\nYou give the command to the computer terminal - ";
        cout << "execute Omega Protocol. \n\nComputer:  I can't do ";
        cout << "that, Isaac. \n\n[Enter] Override ";
        std::cin.ignore();
        std::cin.ignore();
        cout << "\n\nComputer:  Denied. \n\n[Enter] Override";
        std::cin.ignore();

        cout << std::endl << std::endl;

        taskComplete = true;

        return 5;
    }
}

