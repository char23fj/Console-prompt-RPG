/*********************************************************************
** Program: Final Project
** File: supplyroom.hpp
** Author: Charles Jadin
** Date: March 21, 2017
** Description: Declaration of the SupplyRoom class, derived from the
**  Space class.
*********************************************************************/

#ifndef SUPPLYROOM_HPP
#define SUPPLYROOM_HPP
#include "space.hpp"

class SupplyRoom : public Space
{
    public:
        SupplyRoom();
        ~SupplyRoom();
        virtual int itemEffect();
        virtual int interact();
};

#endif
