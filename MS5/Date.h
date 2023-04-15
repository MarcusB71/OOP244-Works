/* Citation and Sources...
Final Project Milestone 5
Module: Date
Filename: Date.h
Version 1.0
Author	Marcus Brown
Email: mbrown106@myseneca.ca
Id: 127900223
Date: 2023/04/15
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#ifndef SDDS_DATE_H_
#define SDDS_DATE_H_
#include <iostream>
#include "Error.h"
#include "POS.h"
#include <ctime>
namespace sdds {
    class Date {
    private:
        int m_year;
        int m_month;
        int m_day;
        int m_hour;
        int m_minute;
        bool m_dateOnly; //no hour or minutes
        Error m_error;
    public:
        Date();
        Date(int year, int month, int day);
        Date(int year, int month, int day, int hour, int minute = 0, bool dateOnly = false);
        void dateValidation();
        void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly = false);
        int uniqueDateValue(int year, int mon, int day, int hour, int min);
        int daysOfMonth(int year, int month);
        bool operator==(const Date& date);
        bool operator!=(const Date& date);
        bool operator<(const Date& date);
        bool operator>(const Date& date);
        bool operator<=(const Date& date);
        bool operator>=(const Date& date);
        Date& dateOnly(bool dateOnly);
        operator bool()const;
        const Error& error()const;
        std::ostream& display(std::ostream& ostr)const;
        std::istream& read(std::istream& istr);
    };
    std::ostream& operator<<(std::ostream& ostr, const Date& date);
    std::istream& operator>>(std::istream& istr, Date& date);
}
#endif
