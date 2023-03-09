#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds
{
    class Numbers
    {
        double* m_collection;
        char m_fileName[255];
        unsigned int m_collectionSize;
        bool m_originalFlag;
        bool m_addedFlag;

        unsigned int countLines(const char* filename);
        void sort(double* collectionPtr, unsigned int size);
        void setEmpty();
        bool load(const char* filename);
        void save(const char* filename)const;
        double max()const;
        double min()const;
        double average()const;

    public:
        Numbers(const char* filename);
        Numbers();
        ~Numbers();
        Numbers(const Numbers& nums);
        Numbers& operator=(const Numbers& nums);
        operator bool()const;
        void sort();
        Numbers& operator+=(double addToList);
        std::ostream& display(std::ostream& ostr = std::cout) const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Numbers& num);
    std::istream& operator>>(std::istream& istr, Numbers& num);
}
#endif // !SDDS_NUMBERS_H_
