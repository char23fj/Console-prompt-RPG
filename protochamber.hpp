/*********************************************************************
** Program: Final Project
** File: protochamber.hpp
** Author: Charles Jadin
** Date: March 21, 2017
** Description: Declaration of the ProtoChamber class, derived from the
**  Space class.
*********************************************************************/

#ifndef PROTOCHAMBER_HPP
#define PROTOCHAMBER_HPP
#include "space.hpp"
#include "game.hpp"

class ProtoChamber : public Space
{
    private:
        Game * currentGame;
    public:
        ProtoChamber();
        ~ProtoChamber();
        virtual int itemEffect();
        virtual int interact();
        void setGamePoint(Game*);
};

#endif
