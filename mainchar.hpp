/*********************************************************************
** Program: Final Project
** File: mainchar.hpp
** Author: Charles Jadin
** Date: March 21, 2017
** Description: Declaration of the MainChar class
*********************************************************************/

#ifndef MAINCHAR_HPP
#define MAINCHAR_HPP
#include <string>
#include <vector>
#include "item.hpp"
#include "space.hpp"
using std::string;
using std::vector;

class MainChar
{
    private:
        Space * location;
        int health;
        vector<Item*> inventory;
    public:
        MainChar();
        ~MainChar();
        MainChar(Space*);
        int move();
        int inventoryMenu(int);
        int getHealth();
        void decHealth();
        Space * getLocation();
        bool invFull();
        void addItem(Item*);
};

#endif
