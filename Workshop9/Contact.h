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
        char m_province[3]{ '\0' };
        char m_postalCode[7]{ '\0' };
    public:
        Contact() = default;
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
