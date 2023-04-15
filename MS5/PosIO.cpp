/* Citation and Sources...
Final Project Milestone 5
Module: PosIO
Filename: PosIO.cpp
Version 1.0
Author	Marcus Brown
Email: mbrown106@myseneca.ca
Id: 127900223
Date: 2023/04/15
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "PosIO.h"
using namespace std;
namespace sdds {
    ostream& operator<<(ostream& ostr, const PosIO& io) {
        io.write(ostr);
        return ostr;
    }
    ofstream& operator<<(ofstream& ofstr, const PosIO& io) {
        io.save(ofstr);
        return ofstr;
    }
    istream& operator>>(istream& istr, PosIO& io) {
        io.read(istr);
        return istr;
    }
    ifstream& operator>>(ifstream& ifstr, PosIO& io) {
        io.load(ifstr);
        return ifstr;
    }

}