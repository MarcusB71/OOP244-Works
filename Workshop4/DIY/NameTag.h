/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Marcus Brown
email: mbrown106@myseneca.ca
id: 127900223
date: 15/02/2023
*/
#ifndef SDDS_NAMETAG_H
#define SDDS_NAMETAG_H
#define MAX_NAME_LENGTH 40
#define MIN_NAME_LENGTH 20
#define MAX_EXT_VALUE 99999
#define MIN_EXT_VALUE 10000

namespace sdds
{
    class NameTag
    {
    private:
        char *m_name;
        int m_extensionNum;

    public:
        NameTag();
        NameTag(const char *m_name);
        NameTag(const char *m_name, int m_extensionNum);
        ~NameTag();
        std::ostream &print() const;
        NameTag &read();
        void setEmpty();
    };
}
#endif