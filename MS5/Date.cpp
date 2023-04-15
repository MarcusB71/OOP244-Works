/* Citation and Sources...
Final Project Milestone 5
Module: Date
Filename: Date.cpp
Version 1.0
Author	Marcus Brown
Email: mbrown106@myseneca.ca
Id: 127900223
Date: 2023/04/15
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include "Date.h"
#include <cstring>
using namespace std;
namespace sdds {
    Date::Date():m_dateOnly(false) {
        getSystemDate(m_year, m_month, m_day, m_hour, m_minute, m_dateOnly);
    }
    Date::Date(int year, int month, int day):m_year(year), m_month(month), m_day(day), m_hour(0), m_minute(0), m_dateOnly(true), m_error(nullptr) {
        // m_error.clear();
        dateValidation();
    }
    Date::Date(int year, int month, int day, int hour, int minute, bool dateOnly):m_year(year), m_month(month), m_day(day), m_hour(hour), m_minute(minute), m_dateOnly(false), m_error(nullptr) {
        // m_error.clear();
        dateValidation();
    }
    void Date::dateValidation() {
        if (m_year < MIN_YEAR || m_year > MAX_YEAR) {
            m_error = "Invalid Year";
        }
        else if (m_month < 1 || m_month > 12)
        {
            m_error = "Invalid Month";
        }
        else if (m_day <1 || m_day > daysOfMonth(m_year, m_month))
        {
            m_error = "Invalid Day";
        }
        else if (m_hour < 0 || m_hour > 23) {
            m_error = "Invalid Hour";
        }
        else if (m_minute < 0 || m_minute > 59)
        {
            m_error = "Invalid Minute";
        }
    }
    void Date::getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly) {
        time_t t = time(NULL);
        tm lt = *localtime(&t);
        day = lt.tm_mday;
        mon = lt.tm_mon + 1;
        year = lt.tm_year + 1900;
        if (dateOnly) {
            hour = min = 0;
        }
        else {
            hour = lt.tm_hour;
            min = lt.tm_min;
        }
    }
    int Date::uniqueDateValue(int year, int mon, int day, int hour, int min) {
        return year * 535680 + mon * 44640 + day * 1440 + hour * 60 + min;
    }
    int Date::daysOfMonth(int year, int month) {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = month >= 1 && month <= 12 ? month : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    bool Date::operator==(const Date& date) {
        return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) == uniqueDateValue(date.m_year, date.m_month, date.m_day, date.m_hour, date.m_minute);
    }
    bool Date::operator!=(const Date& date) {
        return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) != uniqueDateValue(date.m_year, date.m_month, date.m_day, date.m_hour, date.m_minute);
    }
    bool Date::operator<(const Date& date) {
        return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) < uniqueDateValue(date.m_year, date.m_month, date.m_day, date.m_hour, date.m_minute);
    }
    bool Date::operator>(const Date& date) {
        return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) > uniqueDateValue(date.m_year, date.m_month, date.m_day, date.m_hour, date.m_minute);
    }
    bool Date::operator<=(const Date& date) {
        return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) <= uniqueDateValue(date.m_year, date.m_month, date.m_day, date.m_hour, date.m_minute);
    }
    bool Date::operator>=(const Date& date) {
        return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute) >= uniqueDateValue(date.m_year, date.m_month, date.m_day, date.m_hour, date.m_minute);
    }
    Date& Date::dateOnly(bool dateOnly) {
        m_dateOnly = dateOnly;
        if (m_dateOnly)
        {
            m_hour = 0;
            m_minute = 0;
        }
        return *this;
    }
    Date::operator bool()const {
        return !m_error;
    }
    const Error& Date::error()const {
        return m_error;
    }
    ostream& Date::display(ostream& ostr)const {
        if (m_dateOnly)
        {
            ostr.fill('0');
            ostr << m_year << "/";
            ostr.width(2);
            ostr << m_month << "/";
            ostr.width(2);
            ostr << m_day;
        }
        else {
            ostr.fill('0');
            ostr << m_year << "/";
            ostr.width(2);
            ostr << m_month << "/";
            ostr.width(2);
            ostr << m_day << ", ";
            ostr.width(2);
            ostr << m_hour << ":";
            ostr.width(2);
            ostr << m_minute;
        }
        return ostr;
    }
    ostream& operator<<(ostream& ostr, const Date& date) {
        if (bool(date))
        {
            date.display(ostr);
        }
        else {
            ostr << date.error() << "(";
            date.display(ostr);
            ostr << ")";
        }
        return ostr;
    }
    istream& Date::read(istream& istr) {
        m_error.clear();
        m_year = 0;
        m_month = 0;
        m_day = 0;
        m_hour = 0;
        m_minute = 0;
        if (m_dateOnly) {
            istr >> m_year;
            if (!istr.fail())
            {
                istr.ignore();
                istr >> m_month;
                if (!istr.fail())
                {
                    istr.ignore();
                    istr >> m_day;
                    if (!istr.fail())
                    {
                        dateValidation();
                    }
                    else {
                        m_error = "Cannot read day entry";
                    }
                }
                else {
                    m_error = "Cannot read month entry";
                }
            }
            else {
                m_error = "Cannot read year entry";
            }
        }
        else {
            istr >> m_year;
            if (!istr.fail())
            {
                istr.ignore();
                istr >> m_month;
                if (!istr.fail())
                {
                    istr.ignore();
                    istr >> m_day;
                    if (!istr.fail())
                    {
                        istr.ignore();
                        istr >> m_hour;
                        if (!istr.fail())
                        {
                            istr.ignore();
                            istr >> m_minute;
                            if (!istr.fail())
                            {
                                dateValidation();
                            }
                            else {
                                m_error = "Cannot read minute entry";
                            }
                        }
                        else {
                            m_error = "Cannot read hour entry";
                        }
                    }
                    else {
                        m_error = "Cannot read day entry";
                    }
                }
                else {
                    m_error = "Cannot read month entry";
                }
            }
            else {
                m_error = "Cannot read year entry";
            }
        }
        return istr;
    }
    std::istream& operator>>(std::istream& istr, Date& date) {
        date.read(istr);
        return istr;
    }
}