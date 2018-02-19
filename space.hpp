/*********************************************************************
** Program: Final Project
** File: protochamber.hpp
** Author: Charles Jadin
** Date: March 21, 2017
** Description: Declaration of the Space class, a parent class for
**  each of the six rooms in the game.
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP
#include <vector>
#include <string>
using std::vector;
using std::cout;
using std::string;

//Forward declarations; classes include each other
class Item;
class Game;

class Space
{
    protected:
        Space * north;  //Direction pointers
        Space * south;
        Space * east;
        Space * west;
        string imgName;     //Used for displaying script and image files
        string scptName;
        bool searched;
        bool taskComplete;
        vector<Item*> ground;   //Dropped items
        string objective;
    public:
        Space();
        virtual ~Space();
        void showSpace(char);
        void showScript();
        void connect(char, Space*);
        Space * getDirection(char);

        //Next 3 are relevant to only certain classes; default is
        // to show an error message if the override isn't called
        virtual void pointToLocked(Space*) {cout << "error";}
        virtual void setQitem(Item*) {cout << "error";}
        virtual void setGamePoint(Game*) {cout << "error";}

        virtual int itemEffect() = 0;     //Pure virtual
        virtual int interact() = 0;

        bool beenSearched();
        bool complete();
        int showItems();
        int getItems();
        void dropItem(Item*);
        Item * popItem(int);
        string getObjective();
};

#endif
