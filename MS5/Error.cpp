/* Citation and Sources...
Final Project Milestone 4
Module: Error
Filename: Error.cpp
Version 1.0
Author	Marcus Brown
Email: mbrown106@myseneca.ca
Id: 127900223
Date: 2023/04/06
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "Error.h"
#include <cstring>
using namespace std;
namespace sdds {
    Error::Error():m_errDesc(nullptr) {}
    Error::Error(const char* errMsg):m_errDesc(nullptr) {
        if (errMsg != nullptr)
        {
            delete[] m_errDesc;
            m_errDesc = new char[strlen(errMsg) + 1];
            strcpy(m_errDesc, errMsg);
        }
        else {
            errMsg = nullptr;
        }
    }
    Error::Error(const Error& error) {
        m_errDesc = nullptr;
        operator=(error);
    }
    Error& Error::operator=(const Error& error) {
        if (this != &error)
        {
            delete[] m_errDesc;
            if (error.m_errDesc != nullptr)
            {
                m_errDesc = new char[strlen(error.m_errDesc) + 1];
                strcpy(m_errDesc, error.m_errDesc);
            }
            else {
                m_errDesc = nullptr;
            }
        }
        return *this;
    }
    Error& Error::operator=(const char* errorMsg) {
        if (errorMsg != nullptr)
            // if (errorMsg != nullptr && errorMsg != "\0")
        {
            delete[] m_errDesc;
            m_errDesc = new char[strlen(errorMsg) + 1];
            strcpy(m_errDesc, errorMsg);
        }
        else { m_errDesc = nullptr; }
        return *this;
    }
    Error::operator bool()const {
        return m_errDesc != nullptr;
    }
    Error& Error::clear() {
        delete[] m_errDesc;
        m_errDesc = nullptr;
        return *this;
    }
    const char* Error::getError()const {
        return m_errDesc;
    }
    ostream& operator<<(ostream& ostr, const Error& error) {
        if (bool(error))
        {
            ostr << error.getError();
        }
        return ostr;

    }
    Error::~Error() {
        delete[] m_errDesc;
    }
}