/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Marcus Brown
email: mbrown106@myseneca.ca
id: 127900223
date: 22/02/2023
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Bus.h"
using namespace std;
namespace sdds
{
    Bus::Bus(int numSeats, int numPassenger)
    {
        if (numSeats % 2 != 0 || numSeats < 10 || numSeats > 40 || numPassenger < 0 || numPassenger > numSeats)
        {
            setOutOfService();
        }
        else
        {
            m_numPassenger = numPassenger;
            m_numSeats = numSeats;
        }
    }
    void Bus::setOutOfService()
    {
        m_numPassenger = -1; // think i need to change this to 0
        m_numSeats = -1;
    }
    void Bus::drawBus(int seats, int noOfPassengers, ostream &ostr) const
    {
        int i, p;
        ostr.fill('_');
        ostr.width((seats / 2) * 3 + 4);
        ostr << "_";
        ostr << endl
             << "| ";
        for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < noOfPassengers ? '2' : ((p == noOfPassengers) ? '1' : ' ')) << "]")
            ;
        ostr << "|_\\_" << endl;
        ostr << "| ";
        ostr.fill(' ');
        ostr.width(((seats / 2) * 3 - 14) / 2);
        ostr << " "
             << "Seneca College";
        ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
        ostr << " "
             << "    )" << endl;
        ostr << "`---OO";
        ostr.fill('-');
        ostr.width((seats / 2) * 3 - 5);
        ostr << "-"
             << "O---'" << endl;
    }
    ostream &Bus::display(ostream &ostr) const
    {
        if (bool(*this))
        {
            double farePrice = m_numPassenger * BUSPRICE;
            drawBus(m_numSeats, m_numPassenger, ostr);
            cout << "Total Fare Price: " << fixed;
            cout.precision(2);
            cout << farePrice << endl;
        }
        else
        {
            cout << "Out of service!" << endl;
        }
        return ostr;
    }

    istream &Bus::read(istream &istr)
    {
        istr >> m_numSeats;
        istr.ignore();
        istr >> m_numPassenger;
        istr.ignore();
        if (m_numSeats % 2 != 0 || m_numSeats < 10 || m_numSeats > 40 || m_numPassenger < 0 || m_numPassenger > m_numSeats)
        {
            setOutOfService();
        }
        return istr;
    }
    Bus::operator bool() const
    {
        return m_numSeats > 0;
    }
    Bus::operator int() const
    {
        return bool(*this) ? m_numPassenger : -1;
    }
    Bus::operator double() const
    {
        return bool(*this) ? (m_numPassenger * BUSPRICE) : -1.0;
    }
    // check all unary operator function should be returning true and false
    bool Bus::operator--()
    {
        if (bool(*this) && m_numPassenger != 0)
        {
            m_numPassenger--;
            return true;
        }
        return false;
    }
    bool Bus::operator--(int)
    {
        if (bool(*this) && m_numPassenger != 0)
        {
            m_numPassenger--;
            return true;
        }
        return false;
    } // postfix
    bool Bus::operator++()
    {
        if (bool(*this) && m_numPassenger != m_numSeats)
        {
            m_numPassenger++;
            return true;
        }
        return false;
    }
    bool Bus::operator++(int)
    {
        if (bool(*this) && m_numPassenger != m_numSeats)
        {
            m_numPassenger++;
            return true;
        }
        return false;
    } // postfix

    Bus &Bus::operator=(int value)
    {
        m_numPassenger = value;
        if (m_numPassenger > m_numSeats)
        {
            setOutOfService();
        }
        return *this;
    }
    Bus &Bus::operator+=(int value)
    {
        if (bool(*this))
        {
            m_numPassenger += value;
            if (m_numPassenger > m_numSeats)
            {
                setOutOfService();
            }
        }
        return *this;
    }
    Bus &Bus::operator+=(Bus &right)
    {
        if (bool(*this) && bool(right))
        {
            int leftSpots = m_numSeats - m_numPassenger;
            while (leftSpots != 0 && right.m_numPassenger != 0)
            {
                leftSpots--;
                m_numPassenger++;
                right.m_numPassenger--;
            }
        }
        return *this;
    }
    bool Bus::operator==(const Bus &right) const // fix this function
    {
        if (bool(*this) && bool(right))
        {
            return m_numPassenger == right.m_numPassenger;
        }
        return false;
    }
    int operator+(int left, const Bus &right)
    {
        int sum = 0;
        if (bool(right))
        {
            sum = left + right;
            return sum;
        }
        else
        {
            sum = left;
            return sum;
        }
    }
    ostream &operator<<(ostream &ostr, const Bus &right)
    {
        right.display(ostr);
        return ostr;
    }
    istream &operator>>(istream &istr, Bus &right)
    {
        right.read(istr);
        return istr;
    }
    Bus::~Bus()
    {
    }
}