#ifndef SDDS_EGGCARTON_H
#define SDDS_EGGCARTON_H
#include <iostream>
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
        std::ostream &displayCarton(int size, int noOfEggs, bool jumboSize, std::ostream &ostr = std::cout) const;

    public:
        EggCarton(int size = 6, int noOfEggs = 0, bool jumboSize = false);
        ~EggCarton();
        std::ostream &display(std::ostream &ostr = std::cout) const;
        std::istream &read(std::istream &istr = std::cin);
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
    std::ostream &operator<<(std::ostream &ostr, const EggCarton &right);
    std::istream &operator>>(std::istream &istr, EggCarton &right);
}
#endif