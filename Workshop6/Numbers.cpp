#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <cstring>
#include "Numbers.h"
using namespace std;
namespace sdds
{
    void Numbers::sort(double* nums, unsigned int size)
    {
        unsigned int i, j;
        double temp;
        for (i = size - 1; size && i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
    }

    unsigned int Numbers::countLines(const char* filename)
    { /**/
        unsigned int lines = 0u;
        ifstream nums(filename);
        while (nums)
        {
            lines += (nums.get() == '\n');
        }
        return lines;
    }
    // above is provided
    void Numbers::setEmpty()
    {
        m_collection = nullptr;
        m_collectionSize = 0;
        m_originalFlag = false;
        m_addedFlag = false;
    }
    Numbers::Numbers(const char* fileName)
    {
        strcpy(m_fileName, fileName);
        load(fileName);
    }
    Numbers::Numbers()
    {
        setEmpty();
    }
    Numbers::~Numbers()
    {
        save(m_fileName);
        if (m_collection != nullptr)
        {
            delete[] m_collection;
        }
    }
    //copy constructor
    Numbers::Numbers(const Numbers& nums)
    {
        setEmpty();
        *this = nums;
    }
    //copy assignment
    Numbers& Numbers::operator=(const Numbers& nums) {
        if (this != &nums)
        {
            strcpy(m_fileName, nums.m_fileName);
            save(m_fileName);
            delete[] m_collection;
            m_collection = nullptr;
            setEmpty();
            if (nums.m_collectionSize > 0)
            {
                m_originalFlag = false;
                m_collection = new double[nums.m_collectionSize];
                for (unsigned i = 0; i < nums.m_collectionSize; i++)
                {
                    m_collection[i] = nums.m_collection[i];
                }
                m_collectionSize = nums.m_collectionSize;
            }
            else {
                setEmpty();
            }
        }
        return *this;
    }
    bool Numbers::load(const char* filename) {
        double num = 0.0;
        int reads = 0;
        bool loaded = false;
        setEmpty();
        // delete[] m_collection;
        // m_collection = nullptr; 
        int lines = countLines(filename);
        if (lines > 0)
        {
            m_collection = new double[lines];
            std::ifstream file(filename);
            if (file.is_open())
            {
                while (file >> num)
                {
                    m_collection[reads] = num;
                    reads++;
                }
                file.close();
            }
            else {
                cout << "ERROR: Could not open file!" << endl;
            }
        }
        if (lines == reads)
        {
            m_collectionSize = reads;
            m_originalFlag = true;
            loaded = true;
        }
        else {
            setEmpty();
        }
        return loaded;
    }
    void Numbers::save(const char* filename)const {
        if (m_originalFlag && m_addedFlag)
        {
            std::ofstream file(filename);
            if (file.is_open())
            {
                file.setf(ios::fixed);
                file.precision(2);
                for (unsigned i = 0; i < m_collectionSize; i++)
                {
                    file << m_collection[i] << endl;
                }
                file.close();
            }
            else {
                cout << "ERROR: Could not open file!";
            }
        }
    }
    double Numbers::max()const {
        double num = m_collection[0];
        for (unsigned i = 0; i < m_collectionSize; i++)
        {
            if (m_collection[i] > num)
            {
                num = m_collection[i];
            }
        }
        return num;
    }
    double Numbers::min()const {
        double num = m_collection[0];
        for (unsigned i = 0; i < m_collectionSize; i++)
        {
            if (m_collection[i] < num)
            {
                num = m_collection[i];
            }
        }
        return num;
    }
    double Numbers::average()const {
        double num = 0.0;
        for (unsigned i = 0; i < m_collectionSize; i++)
        {
            num += m_collection[i];
        }
        num = num / m_collectionSize;
        return num;
    }
    Numbers::operator bool()const {
        return  m_collectionSize > 0;
    }
    void Numbers::sort() {
        sort(m_collection, m_collectionSize);
    }
    Numbers& Numbers::operator+=(double addToList) {
        if (m_collectionSize > 0)//bool(*this)
        {
            double* temp = new double[m_collectionSize + 1];
            for (unsigned i = 0; i < m_collectionSize; i++)
            {
                temp[i] = m_collection[i];
            }
            temp[m_collectionSize] = addToList;
            delete[] m_collection;
            m_collection = temp;
            m_collectionSize += 1;
            m_addedFlag = true;
        }
        return *this;
    }
    ostream& Numbers::display(ostream& ostr)const {
        if (m_collectionSize > 0)
        {
            ostr.setf(ios::fixed); //MUST HAVE FIXED TO USE FIXED POINT NOTATION (refers to post decimal places)
            ostr.precision(2);
            if (!m_originalFlag)
            {
                ostr << "Copy of ";
            }
            ostr << m_fileName << endl;
            for (unsigned i = 0; i < m_collectionSize; i++)
            {
                ostr << m_collection[i];
                if (i + 1 != m_collectionSize) {
                    ostr << ", ";
                }
            }
            ostr << endl;
            ostr << "----------------------------------------------------------------------------" << endl;
            ostr << "Total of " << m_collectionSize << " number(s), " << "Largest: " << max() << ", Smallest: " << min() << ", Average: " << average() << endl;
            ostr << "============================================================================";
        }
        else {
            ostr << "Empty List";
        }
        return ostr;
    }

    ostream& operator<<(ostream& ostr, const Numbers& num) {
        num.display(ostr);
        return ostr;
    }
    istream& operator>>(istream& istr, Numbers& num) {
        double toAdd = 0.0;
        istr >> toAdd;
        if (toAdd)
        {
            num += toAdd;
        }
        return istr;
    }
}
