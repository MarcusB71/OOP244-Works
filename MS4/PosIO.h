/* Citation and Sources...
Final Project Milestone 4
Module: PosIO
Filename: PosIO.h
Version 1.0
Author	Marcus Brown
Email: mbrown106@myseneca.ca
Id: 127900223
Date: 2023/04/06
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#ifndef SDDS_POSIO_H
#define SDDS_POSIO_H
#include <iostream>
#include <fstream>
namespace sdds {
    class PosIO {
    private:

    public:
        virtual ~PosIO() = default;
        virtual std::ostream& write(std::ostream& ostr)const = 0;
        virtual std::istream& read(std::istream& istr) = 0;
        virtual std::ofstream& save(std::ofstream& ostr)const = 0;
        virtual std::ifstream& load(std::ifstream& istr) = 0;
    };
    std::ostream& operator<<(std::ostream& ostr, const PosIO& io);
    std::ofstream& operator<<(std::ofstream& ofstr, const PosIO& io);
    std::istream& operator>>(std::istream& istr, PosIO& io);
    std::ifstream& operator>>(std::ifstream& ifstr, PosIO& io);
}
#endif