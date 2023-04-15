/* Citation and Sources...
Final Project Milestone 5
Module: NonPerishable
Filename: NonPerishable.h
Version 1.0
Author	Marcus Brown
Email: mbrown106@myseneca.ca
Id: 127900223
Date: 2023/04/15
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#ifndef SDDS_NONPERISHABLE_H
#define SDDS_NONPERISHABLE_H
#include <iostream>
#include "Item.h"
namespace sdds {
    class NonPerishable: public Item {
    private:

    public:
        virtual char itemType()const override;
        std::ostream& write(std::ostream& ostr)const;
    };
}
#endif