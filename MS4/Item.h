/* Citation and Sources...
Final Project Milestone 4
Module: Item
Filename: Item.h
Version 1.0
Author	Marcus Brown
Email: mbrown106@myseneca.ca
Id: 127900223
Date: 2023/04/06
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include <iostream>
#include "PosIO.h"
#include "POS.h"
#include "Error.h"
#include "Date.h"
namespace sdds {
    class Item: public PosIO {
    private:
        char m_SKU[MAX_SKU_LEN + 1];
        char* m_name;
        double m_price;
        bool m_taxed;
        int m_quantity; //stock quantity of the item
    protected:
        int m_displayFlag; //POS_LIST for list mode or POS_FORM for form mode
        Error m_error;
    public:
        Item();
        void setEmpty();
        Item(const Item& item);
        virtual ~Item();
        Item& operator=(const Item& item);
        bool operator==(const char* string)const;
        bool operator>(const Item& item)const;
        int operator+=(int value);
        int operator-=(int value);
        operator bool()const;
        double cost()const;
        int quantity()const;
        virtual char itemType()const = 0;
        Item& displayType(int type);
        Item& clear();
        std::ostream& write(std::ostream& ostr)const;
        std::ofstream& save(std::ofstream& ofstr)const;
        std::istream& read(std::istream& istr);
        std::ifstream& load(std::ifstream& ifstr);
        std::ostream& bprint(std::ostream& ostr)const;
    };
    double& operator+=(double& dValue, const Item& item);



}
#endif