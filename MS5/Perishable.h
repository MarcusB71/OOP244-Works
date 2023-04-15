/* Citation and Sources...
Final Project Milestone 5
Module: Perishable
Filename: Perishable.h
Version 1.0
Author	Marcus Brown
Email: mbrown106@myseneca.ca
Id: 127900223
Date: 2023/04/15
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include <iostream>
#include "Item.h"
namespace sdds {

    class Perishable: public Item {
    private:
        Date m_date;
    public:
        char itemType()const;
        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& ostr)const;
        std::ifstream& load(std::ifstream& ifstr);
        std::ofstream& save(std::ofstream& ofstr)const;
    };


}
#endif