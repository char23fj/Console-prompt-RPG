/*********************************************************************
** Program: Final Project
** File: office.hpp
** Author: Charles Jadin
** Date: March 21, 2017
** Description: Declaration of the WorkArea class, derived from the
**  Space class.
*********************************************************************/

#ifndef OFFICE_HPP
#define OFFICE_HPP
#include "space.hpp"

class Office : public Space
{
    private:
        Space * front;
    public:
        Office();
        ~Office();
        virtual void pointToLocked(Space*);
        virtual int itemEffect();
        virtual int interact();
};

#endif
