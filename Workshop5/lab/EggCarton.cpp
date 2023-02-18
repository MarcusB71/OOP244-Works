#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "EggCarton.h"
using namespace std;
namespace sdds
{
    EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize)
    {
        if (size % 6 != 0 || (size < 6 || size > 36) || (noOfEggs < 0 || noOfEggs > size))
        {
            setBroken(-1, -1);
        }
        else
        {
            m_size = size;
            m_noOfEggs = noOfEggs;
            m_jumboSize = jumboSize;
        }
    }
    EggCarton &EggCarton::setBroken(int size, int noOfEggs)
    {
        m_size = size;
        m_noOfEggs = noOfEggs;
        return *this;
    }
    ostream &EggCarton::display(ostream &ostr) const
    {
        if (bool(*this))
        {
            displayCarton(m_size, m_noOfEggs, m_jumboSize, ostr);
        }
        else
        {
            ostr << "Broken Egg Carton!" << endl;
        }
        return ostr;
    }
    ostream &EggCarton::displayCarton(int size, int noOfEggs, bool jumbo, ostream &ostr) const
    {
        int cartonWidth = size == 6 ? 3 : 6;
        for (int i = 0; i < size; i++)
        {
            ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' ');
            ((i + 1) % cartonWidth == 0) && ostr << ']' << endl;
        }
        return ostr;
    }
    istream &EggCarton::read(istream &istr)
    {
        char readJumbo;
        istr >> readJumbo;
        if (readJumbo == 'j')
        {
            m_jumboSize = true;
        }
        else
        {
            m_jumboSize = false;
        }
        istr.ignore(1);
        istr >> m_size;
        istr.ignore(1);
        istr >> m_noOfEggs;
        if (m_size % 6 != 0 || (m_size < 6 || m_size > 36) || (m_noOfEggs < 0 || m_noOfEggs > m_size))
        {
            setBroken(-1, -1);
        }
        return istr;
    }
    EggCarton::operator bool() const
    {
        return m_size > 0;
    }
    EggCarton::operator int() const
    {
        return bool(*this) ? m_noOfEggs : -1;
    }
    EggCarton::operator double() const
    {
        double total = 0.0;
        if (bool(*this))
        {
            if (m_jumboSize)
            {
                total = (m_noOfEggs * JumboEggWieght) / 1000.0;
            }
            else
            {
                total = (m_noOfEggs * RegularEggWieght) / 1000.0;
            }
            return total;
        }
        return -1;
    }
    EggCarton &EggCarton::operator--()
    {
        if (bool(*this) && m_noOfEggs > 0)
        {
            m_noOfEggs--;
        }
        return *this;
    }
    EggCarton EggCarton::operator--(int)
    {
        EggCarton backup(*this);
        --(*this);
        return backup;
    } // postfix
    EggCarton &EggCarton::operator++()
    {
        if (bool(*this))
        {
            m_noOfEggs++;
            if (m_noOfEggs > m_size)
            {
                setBroken(-1, -1);
            }
        }
        return *this;
    }
    EggCarton EggCarton::operator++(int)
    {
        EggCarton backup(*this);
        ++(*this);
        return backup;
    } // postfix
    EggCarton &EggCarton::operator=(int value)
    {
        m_noOfEggs = value;
        if (m_noOfEggs > m_size)
        {
            setBroken(-1, -1);
        }
        return *this;
    }
    // EggCarton &EggCarton::operator=(EggCarton &right)
    // {
    //     m_size = right.m_size;
    //     m_noOfEggs = right.m_noOfEggs;
    //     m_jumboSize = right.m_jumboSize;

    //     return *this;
    // }
    EggCarton &EggCarton::operator+=(int value)
    {
        if (bool(*this))
        {
            m_noOfEggs += value;
            if (m_noOfEggs > m_size)
            {
                setBroken(-1, -1);
            }
        }
        return *this;
    }
    EggCarton &EggCarton::operator+=(EggCarton &right) // maybe fix this too
    {
        if (bool(*this))
        {
            int leftSpots = m_size - m_noOfEggs;
            while (leftSpots != 0 && right.m_noOfEggs != 0)
            {
                leftSpots--;
                m_noOfEggs++;
                right.m_noOfEggs--;
            }
        }
        return *this;
    }
    bool EggCarton::operator==(const EggCarton &right) const // fix this function
    {
        double difference = double(m_jumboSize) - double(right.m_jumboSize);
        if (difference >= -0.001 && difference <= 0.001)
        {
            return false;
        }
        return true;
    }
    int operator+(int left, const EggCarton &right)
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
    ostream &operator<<(ostream &ostr, const EggCarton &right)
    {
        right.display(ostr);
        return ostr;
    }
    istream &operator>>(istream &istr, EggCarton &right)
    {
        right.read(istr);
        return istr;
    }
    EggCarton::~EggCarton()
    {
    }
}