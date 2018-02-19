/*********************************************************************
** Program: Final Project
** File: space.cpp
** Author: Charles Jadin
** Date: March 21, 2017
** Description: Function implementations for the Space class,
**  from which all other rooms are derived.
*********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "space.hpp"
#include "item.hpp"
#include "game.hpp"
using std::cout;
using std::cin;
using std::string;

/*********************************************************************
** Constructor; sets pointers to null
*********************************************************************/
Space::Space()
{
    north = NULL;
    south = NULL;
    east = NULL;
    west = NULL;
}

/*********************************************************************
** Destructor; sets pointers to null
*********************************************************************/
Space::~Space()
{
    north = NULL;
    south = NULL;
    east = NULL;
    west = NULL;
}

/*********************************************************************
** Reads a txt file with an image of the Space; the char argument
**  determines whether it displays the regular file or one with an
**  attacking robot
*********************************************************************/
void Space::showSpace(char add)
{
    std::ifstream image;
    string fName = imgName + add;   //Add argument char ('1' or '2')
    fName += ".txt";
    image.open(fName);

    if (!image)
    {
        cout << "\nImage file cannot be displayed.\n";
    }

    string display;

    while (image)
    {
        display = "";
        std::getline(image, display);
        cout << display << std::endl;
    }
}

/*********************************************************************
** Displays text from a file; this text contains a description of the
**  Space (used when the room is searched).
*********************************************************************/
void Space::showScript()
{
    std::ifstream script;
    string fName = scptName;
    fName += ".txt";
    script.open(fName);

    if (!script)
    {
        cout << "\nScript file cannot be displayed.\n";
    }

    string display;

    while (script)
    {
        display = "";
        std::getline(script, display);
        cout << display << std::endl;
    }

    cout << "\nPress [Enter] to continue.  ";
    std::cin.ignore();
    std::cin.ignore();
    cout << std::endl << std::endl;

    searched = true;
}

/*********************************************************************
** Connects a pointer to another room (pointer is determined by the
**  char argument)
*********************************************************************/
void Space::connect(char dir, Space * nextRoom)
{
    switch (dir)
    {
        case 'n':
        {
            north = nextRoom;
            break;
        }

        case 's':
        {
            south = nextRoom;
            break;
        }

        case 'e':
        {
            east = nextRoom;
            break;
        }

        case 'w':
        {
            west = nextRoom;
            break;
        }
    }
}

/*********************************************************************
** Returns a direction pointer (pointer is determined by the char
**  argument)
*********************************************************************/
Space * Space::getDirection(char d)
{
    switch (d)
    {
        case 'n':
        {
            return north;
        }

        case 's':
        {
            return south;
        }

        case 'e':
        {
            return east;
        }

        case 'w':
        {
            return west;
        }

        default:
        {
            return NULL;
        }
    }
}

/*********************************************************************
** Returns whether the room has been searched
*********************************************************************/
bool Space::beenSearched()
{
    return searched;
}

/*********************************************************************
** Returns whether the Space's objective has been completed
*********************************************************************/
bool Space::complete()
{
    return taskComplete;
}

/*********************************************************************
** Returns number of items on the ground
*********************************************************************/
int Space::getItems()
{
    return ground.size();
}

/*********************************************************************
** Shows items on the ground and displays a menu allowing the user to
**  choose an item to pick up
*********************************************************************/
int Space::showItems()
{
    if (ground.empty())
    {
        cout << "\nNo items available here.\n";
        return 0;
    }

    cout << "\nItems available here:\n";

    for (int x = 0; x < ground.size(); x++)
    {
        cout << x + 1 << " - " << (*ground[x]).getName() << std::endl;
    }

    int index = ground.size() + 10;

    while (index < 0 || index > ground.size())
    {
        cout << "\nChoose the number of the item you want to take.\n";
        cout << "(0 --> BACK) ";
        cin >> index;
    }

    return index;
}

/*********************************************************************
** Pushes an item pointer to the "ground" vector when the character
**  drops it
*********************************************************************/
void Space::dropItem(Item * tossed)
{
    ground.push_back(tossed);
}

/*********************************************************************
** Pops item from ground and returns it so the character can pick it up
*********************************************************************/
Item * Space::popItem(int x)
{
    Item * pickup = ground[x];
    ground[x] = ground.back();
    ground.pop_back();

    return pickup;
}

/*********************************************************************
** Returns the Space's interaction objective
*********************************************************************/
string Space::getObjective()
{
    return objective;
}