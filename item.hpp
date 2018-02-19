/*********************************************************************
** Program: Final Project
** File: item.hpp
** Author: Charles Jadin
** Date: March 21, 2017
** Description: Declaration of the item class
*********************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
using std::string;

class Space;    //Forward declaration (Item includes a Space pointer,
                // Space includes an Item pointer
class Item
{
    private:
        string itemName;
        string info;
        char itemType;  //'q' for quest, 'w' for weapon
        int usesLeft;
        Space * usefulHere;
    public:
        Item();
        ~Item();
        Item(string, string, int, char, Space*);
        string getName();
        string getInfo();
        char getType();
        int getUses();
        int useItem(Space*);
        int useItem(int);
};

#endif
