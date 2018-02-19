/*********************************************************************
** Program: Final Project
** File: mainchar.hpp
** Author: Charles Jadin
** Date: March 21, 2017
** Description: Declaration of the MainChar class
*********************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include "mainchar.hpp"
using std::cout;
using std::cin;
using std::string;

/*********************************************************************
** Default constructor; sets null location and 0 health
*********************************************************************/
MainChar::MainChar()
{
    location = NULL;
    health = 0;
}

/*********************************************************************
** Destructor; sets location to null
*********************************************************************/
MainChar::~MainChar()
{
    location = NULL;
}

/*********************************************************************
** Constructor; sets 2 health and starting location to argument pointer
*********************************************************************/
MainChar::MainChar(Space * starting)
{
    location = starting;
    health = 2;
}

/*********************************************************************
** Moves the character to a new Space based on user input
*********************************************************************/
int MainChar::move()
{
    char dir = '0';
    cout << "\nWhich direction? ";
    while (dir != 'n' && dir != 's' && dir != 'e' && dir != 'w')
    {
        cout << "Choose ['n', 's', 'e', 'w']  ";
        cin >> dir;
        cout << std::endl;
    }

    if ((*location).getDirection(dir) == NULL)
    {
        cout << "\nYou can't travel there.\n";
        return 0;
    }

    else
    {
        location = (*location).getDirection(dir);
        return 1;
    }
}

/*********************************************************************
** Shows inventory menu and allows user to choose an item, and then
**  choose to use the item, view its description, or drop it.
*********************************************************************/
int MainChar::inventoryMenu(int threat)
{
    int itemUsed = 0;

    if (inventory.empty())      //If inventory empty (never happens)
    {
        cout << "\nNothing in inventory.\n";
        return 0;
    }

    cout << "\nInventory:\n";

    //Show inventory
    for (int x = 0; x < inventory.size(); x++)
    {
        cout << x + 1 << " - " << (*inventory[x]).getName() << "\n";
    }

    //Choose an item
    int iSel = inventory.size() + 10;
    while (iSel < 0 || iSel > inventory.size())
    {
        cout << "\nSelect an item 1 - " << inventory.size();
        cout << "  (0 --> BACK).  ";
        cin >> iSel;
    }

    if (iSel == 0)
    {
        return 0;
    }

    iSel--;

    Item * selected = inventory[iSel];

    //Options for chosen item
    cout << std::endl << (*selected).getName() << " - options:\n";
    cout << "1 - USE \n2 - INFO \n3 - DROP \n0 - BACK  ";

    //Choose options for an item
    char opt = 'Z';
    while (opt != 0)
    {
        cin >> opt;

        //Use a quest item
        if (opt == '1' && (*selected).getType() == 'q')
        {
            itemUsed += (*selected).useItem(location);
            break;
        }

        else if (opt == '1')    //Use a weapon
        {
            itemUsed -= (*selected).useItem(threat);
            if (threat < 2)
            {
                cout << "\nYou've deactivated the robot.";
            }

            //If the weapon is the wrench
            if (threat < 2 && (*selected).getName() == "Wrench")
            {
                int flip = rand() % 2;
                if (flip == 1)
                {
                    health--;
                    cout << "..but you lost some health.";
                }
            }
            break;
        }

        else if (opt == '2')    //Get item info
        {
            cout << std::endl << (*selected).getInfo() << std::endl;
            break;
        }

        else if (opt == '3')    //Drop item
        {
            if ((*selected).getName() == "Wrench")
            {
                cout << "\nCan't drop that item.\n";
                break;
            }

            cout << "\nDropped " << (*selected).getName() << ".\n";
            (*location).dropItem(selected);
            selected = inventory.back();
            inventory.at(iSel) = selected;
            inventory.pop_back();

            break;
        }

        else if (opt == '0')    //"Back"
        {
            break;
        }

        else    //Input not recognized; show menu again
        {
            cout << "1 - USE \n2 - INFO \n3 - DROP \n0 - BACK  ";
        }

    }

    if ((*selected).getUses() <= 0)     //Check for destroyed item
    {
        cout << "  " << (*selected).getName() << " is no longer usable.\n";
        selected = inventory.back();
        inventory.at(iSel) = selected;
        inventory.pop_back();
    }
 
    cout << std::endl;

    selected = NULL;

    return itemUsed;    //Return value advances threat countdown

}

/*********************************************************************
** Getter; returns health
*********************************************************************/
int MainChar::getHealth()
{
    return health;
}

/*********************************************************************
** Reduces health by one
*********************************************************************/
void MainChar::decHealth()
{
    health--;
}

/*********************************************************************
** Getter; returns location pointer
*********************************************************************/
Space * MainChar::getLocation()
{
    return location;
}

/*********************************************************************
** Checks if inventory is full (5 items)
*********************************************************************/
bool MainChar::invFull()
{
    if (inventory.size() == 5)
    {
        cout << "\nInventory is full.\n";
        return true;
    }

    else
    {
        return false;
    }
}

/*********************************************************************
** Adds item to inventory
*********************************************************************/
void MainChar::addItem(Item * acquired)
{
    inventory.push_back(acquired);
}