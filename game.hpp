/*********************************************************************
** Program: Final Project
** File: game.hpp
** Author: Charles Jadin
** Date: March 21, 2017
** Description: Declaration of the Game class
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include "item.hpp"
#include "mainchar.hpp"
#include "fronthall.hpp"
#include "workarea.hpp"
#include "office.hpp"
#include "supplyroom.hpp"
#include "protochamber.hpp"
#include "terminalroom.hpp"

class Space;

class Game
{
    private:
        MainChar proko;
        Space * currentArea;
        Space * finalArea;
        bool gameFinished;
        int threatLevel;
        Item wrench;
        Item efi;
        Item ild;
        Item key;
        Item pwrCell;

    public:
        Game();
        ~Game();
        void runGame();
        void menu();
        int action(char);
        void spawnRobot();
        void reduceThreat(int);
        void longScript(string);
        void createItems();
};

#endif
