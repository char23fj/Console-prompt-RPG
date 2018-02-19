/*********************************************************************
** Program: Final Project
** File: fronthall.hpp
** Author: Charles Jadin
** Date: March 21, 2017
** Description: Declaration of the FrontHall class, derived from the
**  Space class.
*********************************************************************/

#ifndef FRONTHALL_HPP
#define FRONTHALL_HPP
#include "space.hpp"

class FrontHall : public Space
{
    private:
        Space * terminal;
    public:
        FrontHall();
        ~FrontHall();
        virtual void pointToLocked(Space*);
        virtual int itemEffect();
        virtual int interact();
};

#endif
