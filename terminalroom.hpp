/*********************************************************************
** Program: Final Project
** File: terminalroom.hpp
** Author: Charles Jadin
** Date: March 21, 2017
** Description: Declaration of the TerminalRoom class, derived from
**  the Space class
*********************************************************************/

#ifndef TERMINALROOM_HPP
#define TERMINALROOM_HPP
#include "space.hpp"

class TerminalRoom : public Space
{
    public:
        TerminalRoom();
        ~TerminalRoom();
        virtual int itemEffect();
        virtual int interact();
};

#endif
