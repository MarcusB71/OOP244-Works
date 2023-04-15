/* Citation and Sources...
Final Project Milestone 4
Module: NonPerishable
Filename: NonPerishable.cpp
Version 1.0
Author	Marcus Brown
Email: mbrown106@myseneca.ca
Id: 127900223
Date: 2023/04/06
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "NonPerishable.h"
using namespace std;
namespace sdds {
    char NonPerishable::itemType()const {
        return 'N';
    }
    ostream& NonPerishable::write(ostream& ostr)const {
        Item::write(ostr);
        if (*this)
        {
            if (m_displayFlag == POS_LIST)
            {
                cout << "     N / A   |";
            }
            else {
                cout << "=============^" << endl;
            }
        }
        return ostr;
    }
}