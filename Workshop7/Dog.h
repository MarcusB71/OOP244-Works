/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Marcus Brown
email: mbrown106@myseneca.ca
id: 127900223
date: 16/03/2023
*/
#ifndef SDDS_DOG_H_
#define SDDS_DOG_H_
#include "Pet.h"
namespace sdds {
    class Dog: public Pet {
    private:
        const double COST_BASE = 4.00;// Dog Fee: Initial purchase
        const double COST_FEED = 0.25;// Dog Fee: For each feeding
        const double COST_REVIVE = 1.00;// Dog Fee: Respawn if perished
        int m_numWalks;
    public:
        Dog(const char* name, int age = 0);
        void feed();
        using Pet::feed;
        void walk();
        void reSpawn();
        using Pet::reSpawn;
        void operator++(int);
        using Pet::operator++;
        Dog& operator=(const Dog& dog);
    };
    std::ostream& operator<<(std::ostream& ostr, Dog& RDog);
}
#endif