/* Citation and Sources...
Final Project Milestone 3
Module: Error
Filename: Error.h
Version 1.0
Author	Marcus Brown
Email: mbrown106@myseneca.ca
Id: 127900223
Date: 2023/04/03
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/#ifndef SDDS_ERROR_H_
#define SDDS_ERROR_H_
#include <iostream>
namespace sdds {
    class Error
    {
    private:
        char* m_errDesc; //if null there is no error
    public:
        Error();
        Error(const char* errMsg);
        Error(const Error& error);
        Error& operator=(const Error& error);
        Error& operator=(const char* errorMsg);
        operator bool()const;
        Error& clear();
        const char* getError()const;
        ~Error();
    };
    std::ostream& operator<<(std::ostream& ostr, const Error& error);
}
#endif