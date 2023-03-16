/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Marcus Brown
email: mbrown106@myseneca.ca
id: 127900223
date: 16/03/2023
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Fish.h"
#include <iostream>
using namespace std;
namespace sdds {

    Fish::Fish(const char* name, int age):Pet(name, age, COST_BASE) {
    }
    void Fish::feed() {
        Pet::feed();
        if (Pet::isAlive())
        {
            Pet::addCharge(COST_FEED);
        }
    }
    void Fish::reSpawn() {
        Pet::reSpawn();
        Pet::addCharge(COST_REVIVE);
    }
    void Fish::operator++(int) {
        if (Pet::isAlive())
        {
            double healthDelta = 0.0;
            healthDelta += 0.20 * (getFeeds() - 1);
            Pet::applyHealthDelta(healthDelta);
            Pet::operator++(1);
        }
    }
    Fish& Fish::operator=(const Fish& fish) {
        Pet::operator=(fish);
        double charge = (COST_BASE) * 2;
        Pet::addCharge(charge);
        return *this;
    }
    ostream& operator<<(ostream& ostr, Fish& RFish) {
        ostr << "** Generic Fish **" << endl;
        RFish.outputData(ostr);
        return ostr;
    }
}