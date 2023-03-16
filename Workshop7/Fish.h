/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Marcus Brown
email: mbrown106@myseneca.ca
id: 127900223
date: 16/03/2023
*/
#ifndef SDDS_FISH_H_
#define SDDS_FISH_H_
#include "Pet.h"
namespace sdds {
    class Fish: public Pet {
    private:
        const double COST_BASE = 2.00;// Fish Fee: Initial purchase
        const double COST_FEED = 0.10;// Fish Fee: For each feeding
        const double COST_REVIVE = 0.50;// Fish Fee: Respawn if perished

    public:
        Fish(const char* name, int age = 0);
        void feed();
        using Pet::feed;
        void reSpawn();
        using Pet::reSpawn;
        void operator++(int); // post-fix
        using Pet::operator++;
        Fish& operator=(const Fish& fish);
    };
    std::ostream& operator<<(std::ostream& ostr, Fish& RFish);
}
#endif