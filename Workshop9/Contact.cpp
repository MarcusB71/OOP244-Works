/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Marcus Brown
email: mbrown106@myseneca.ca
id: 127900223
date: 30/03/2023
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Contact.h"
using namespace std;
namespace sdds {
    Contact::Contact():Person() {}
    Contact::Contact(const Contact& contact):Person(contact) {
        operator=(contact);
    }
    Contact& Contact::operator=(const Contact& contact) {
        if (this != &contact)
        {
            Person::operator=(contact);
            delAlloCopy(m_address, contact.m_address);
            delAlloCopy(m_city, contact.m_city);
            strCpy(m_province, contact.m_province);
            strCpy(m_postalCode, contact.m_postalCode);
        }
        return *this;
    }
    istream& Contact::read(istream& istr) {
        Person::read(istr);
        ~*this;
        m_address = dynRead(istr, ',');
        if (m_address == nullptr || *m_address == '\0')
        {
            istr.setstate(ios::failbit);
        }
        m_city = dynRead(istr, ',');
        if (m_city == nullptr || *m_city == '\0')
        {
            istr.setstate(ios::failbit);
        }
        istr.get(m_province, 4, ',');
        istr.ignore();
        if (m_province[2] != '\0')
        {
            istr.setstate(ios::failbit);
        }
        istr.get(m_postalCode, 8, '\n');
        if (m_postalCode[6] != '\0')
        {
            istr.setstate(ios::failbit);
        }
        if (istr.fail()) {
            ~*this;
        };
        return istr;
    }
    ostream& Contact::write(ostream& ostr)const {
        Person::write(ostr);
        if (*this)
        {
            ostr << endl;
            ostr << m_address << endl;
            ostr << m_city << " " << m_province << endl;
            ostr << m_postalCode[0] << m_postalCode[1] << m_postalCode[2] << " " << m_postalCode[3] << m_postalCode[4] << m_postalCode[5];
        }
        return ostr;
    }
    Contact::operator bool()const {
        return m_address && m_city && m_postalCode[0] && m_province[0];
    }
    void Contact::operator~() {
        delete[] m_address;
        delete[]m_city;
        m_address = m_city = nullptr;
    }
    Contact::~Contact() {
        ~*this;
    }
}