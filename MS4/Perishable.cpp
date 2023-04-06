/* Citation and Sources...
Final Project Milestone 4
Module: Perishable
Filename: Perishable.cpp
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
#include "Perishable.h"
using namespace std;
namespace sdds {
    char Perishable::itemType()const {
        return 'P';
    }
    istream& Perishable::read(istream& istr) {
        Item::read(istr);
        if (*this && istr)
        {
            Date temp;
            temp.dateOnly(true);
            cout << "Expiry date(YYYY/MM/DD)" << endl;
            cout << "> ";
            istr >> temp;
            if (temp)
            {
                m_date = temp;
            }
            else {
                m_error = temp.error();
            }
        }
        return istr;
    }
    ostream& Perishable::write(ostream& ostr)const {
        Item::write(ostr);
        if (*this)
        {
            if (m_displayFlag == POS_LIST)
            {
                cout << " " << m_date << " " << "|";
            }
            else {
                cout << "Expiry Date: " << m_date << endl;
                cout << "=============^" << endl;
            }
        }
        return ostr;
    }
    ifstream& Perishable::load(ifstream& ifstr) {
        Item::load(ifstr);
        if (*this && ifstr)
        {
            Date temp;
            temp.dateOnly(true);
            ifstr.ignore();
            ifstr >> temp;
            if (temp)
            {
                m_date = temp;
            }
            else {
                m_error = temp.error();
            }
        }
        return ifstr;
    }
    ofstream& Perishable::save(ofstream& ofstr)const {
        Item::save(ofstr);
        if (*this && ofstr)
        {
            ofstr << "," << m_date;
        }
        return ofstr;
    }
}