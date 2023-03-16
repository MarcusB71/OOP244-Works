/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Marcus Brown
email: mbrown106@myseneca.ca
id: 127900223
date: 16/03/2023
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Dog.h"
#include <iostream>
using namespace std;
namespace sdds {

    Dog::Dog(const char* name, int age):Pet(name, age, COST_BASE) {
        m_numWalks = 0;
    }
    void Dog::operator++(int) {
        if (Pet::isAlive())
        {
            double healthDelta = 0.0;
            healthDelta += 0.15 * (getHugs() - 1);
            healthDelta += 0.10 * (getFeeds() - 2);
            healthDelta += 0.10 * (getGrooms() - 1);
            healthDelta += 0.20 * (m_numWalks - 2);
            Pet::applyHealthDelta(healthDelta);
            Pet::operator++(1);
        }
    }
    Dog& Dog::operator=(const Dog& dog) {
        Pet::operator=(dog);
        m_numWalks = dog.m_numWalks;
        double charge = (COST_BASE) * 2;
        Pet::addCharge(charge);
        return *this;
    }
    ostream& operator<<(ostream& ostr, Dog& RDog) {
        cout << "** Generic Dog **" << endl;
        RDog.outputData(ostr);
        return ostr;
    }
    void Dog::feed() {
        Pet::feed();
        if (Pet::isAlive())
        {
            Pet::addCharge(COST_FEED);
        }
    }
    void Dog::walk() {
        if (Pet::isAlive())
        {
            m_numWalks++;
        }
    }
    void Dog::reSpawn() {
        Pet::reSpawn();
        Pet::addCharge(COST_REVIVE);
        m_numWalks = 0;
    }
}