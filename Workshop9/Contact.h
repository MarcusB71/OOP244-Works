/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Marcus Brown
email: mbrown106@myseneca.ca
id: 127900223
date: 30/03/2023
*/
#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include "Person.h"
#include "Tools.h"
#include <iostream>
namespace sdds {

    class Contact: public Person {
    private:
        char* m_address{nullptr};
        char* m_city{ nullptr };
        char m_province[4]{ '\0' };
        char m_postalCode[8]{ '\0' };
    public:
        Contact();
        ~Contact();
        Contact(const Contact& contact);
        Contact& operator=(const Contact& contact);
        std::istream& read(std::istream& istr);
        std::ostream& write(std::ostream& ostr)const;
        operator bool()const;
        void operator~();
    };
}
#endif
