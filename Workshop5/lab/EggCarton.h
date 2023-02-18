#ifndef SDDS_EGGCARTON_H
#define SDDS_EGGCARTON_H
#include <iostream>
using namespace std;
namespace sdds
{
    const int RegularEggWieght = 50; // grams
    const int JumboEggWieght = 75;   // grams
    class EggCarton
    {
    private:
        int m_size;
        int m_noOfEggs;
        bool m_jumboSize;
        EggCarton &setBroken(int size, int noOfEggs);
        ostream &displayCarton(int size, int noOfEggs, bool jumboSize, ostream &ostr = cout) const;

    public:
        EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);
        ~EggCarton();
        ostream &display(ostream &ostr = cout) const;
        istream &read(istream &istr = cin);
        operator bool() const;
        operator int() const;
        operator double() const;
        EggCarton &operator--();
        EggCarton operator--(int); // postfix
        EggCarton &operator++();
        EggCarton operator++(int); // postfix
        // EggCarton &EggCarton::operator=(EggCarton &right);
        EggCarton &operator=(int value);
        EggCarton &operator+=(int value);
        EggCarton &operator+=(EggCarton &right);
        bool operator==(const EggCarton &right) const;
    };
    int operator+(int left, const EggCarton &right);
    ostream &operator<<(ostream &ostr, const EggCarton &right);
    istream &operator>>(istream &istr, EggCarton &right);
}
#endif