/*********************************************************************
** Program: Final Project
** File: workarea.hpp
** Author: Charles Jadin
** Date: March 21, 2017
** Description: Declaration of the WorkArea class, derived from the
**  Space class.
*********************************************************************/

#ifndef WORKAREA_HPP
#define WORKAREA_HPP
#include "space.hpp"
#include "item.hpp"

class WorkArea : public Space
{
    private:
        Item loopDev;
    public:
        WorkArea();
        ~WorkArea();
        virtual void setQitem(Item*);
        virtual int itemEffect();
        virtual int interact();
};

#endif

