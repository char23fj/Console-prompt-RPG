/*********************************************************************
** Program: Final Project
** File: item.cpp
** Author: Charles Jadin
** Date: March 21, 2017
** Description: Function implementations for the item class.
*********************************************************************/

#include <iostream>
#include <string>
#include "item.hpp"
#include "space.hpp"
using std::cout;
using std::string;

/*********************************************************************
** Default Constructor
*********************************************************************/
Item::Item()
{
    itemName = 'x';
    info = "x";
    usesLeft = 0;
    itemType = 'x';
    usefulHere = NULL;
}

/*********************************************************************
** Destructor; sets area-of-use pointer to null
*********************************************************************/
Item::~Item()
{
    usefulHere = NULL;
}

/*********************************************************************
** Constructor with paramters to set values
*********************************************************************/
Item::Item(string n, string i, int ul, char t, Space * s)
{
    itemName = n;
    info = i;
    usesLeft = ul;
    itemType = t;
    usefulHere = s;
}

/*********************************************************************
** Getter; returns itemName
*********************************************************************/
string Item::getName()
{
    return itemName;
}

/*********************************************************************
** Getter; returns info
*********************************************************************/
string Item::getInfo()
{
    return info;
}

/*********************************************************************
** Getter; returns itemType char
*********************************************************************/
char Item::getType()
{
    return itemType;
}

/*********************************************************************
** Returns number of uses remaining
*********************************************************************/
int Item::getUses()
{
    return usesLeft;
}

/*********************************************************************
** Uses a quest item, calling its relevant Space's itemEffect if the
**  argument pointer equals the usefulHere pointer.
*********************************************************************/
int Item::useItem(Space * current)
{
    if (current == usefulHere)
    {
        (*usefulHere).itemEffect();
        usesLeft--;
        return 1;
    }

    else
    {
        cout << "\nIt looks like this item doesn't work here...\n";
        return 0;
    }
}

/*********************************************************************
** Uses a weapon item; returns a value for threat reduction if the
**  threat argument is 1 or lower, or prints a message otherwise
*********************************************************************/
int Item::useItem(int time)
{
    if (time <= 1)
    {
        usesLeft--;
        return 3;
    }

    else
    {
        cout << "\nIt looks like this item doesn't work here...\n";
        return 0;
    }
}

