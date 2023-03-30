#define _CRT_SECURE_NO_WARNINGS
#include "Contact.h"
using namespace std;
namespace sdds {
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
        m_city = dynRead(istr, ',');
        char* temp = dynRead(istr, ',');
        strCpy(m_postalCode, temp);
        if (strLen(temp) != 2)
        {
            istr.fail();
        }
        char* temp2 = dynRead(istr);
        strCpy(m_postalCode, temp2);
        // if (strLen(temp2) != 2)
        // {
        //     istr.fail();
        // }


        // istr.getline(m_province, 100, ',');
        // istr.getline(m_postalCode, 100, '\n');
        // if (strLen(m_province) != 2)
        // {
        //     istr.setstate(ios::failbit);
        // }
        if (istr.fail()) ~*this;
        return istr;
    }
    ostream& Contact::write(ostream& ostr)const {
        Person::write(ostr);
        if (*this)
        {
            ostr << endl;
            ostr << m_address << endl;
            ostr << m_city << " " << m_province << endl;
            ostr << m_postalCode << endl;
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