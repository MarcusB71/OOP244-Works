/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Marcus Brown
email: mbrown106@myseneca.ca
id: 127900223
date: 22/02/2023
*/
#ifndef SDDS_BUS_H_
#define SDDS_BUS_H_
#include <iostream>
#define BUSPRICE 125.34
namespace sdds
{
    class Bus
    {
    private:
        int m_numSeats;
        int m_numPassenger;
        void drawBus(int numSeats, int numPassenger, std::ostream &ostr) const;

    public:
        Bus(int numSeats = 20, int numPassenger = 0);
        ~Bus();
        void setOutOfService();
        std::ostream &display(std::ostream &ostr = std::cout) const;
        std::istream &read(std::istream &istr = std::cin);
        int getNumPass() const;
        operator bool() const;
        operator int() const;
        operator double() const;
        // unary op overloads
        bool operator--();
        bool operator--(int); // postfix
        bool operator++();
        bool operator++(int); // postfix
        // binary op overloads
        Bus &operator=(int value);
        Bus &operator+=(int value);
        Bus &operator+=(Bus &right);
        bool operator==(const Bus &right) const;
    };
    int operator+(int left, const Bus &right);
    std::ostream &operator<<(std::ostream &ostr, const Bus &right);
    std::istream &operator>>(std::istream &istr, Bus &right);
}
#endif