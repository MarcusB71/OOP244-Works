/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Marcus Brown
email: mbrown106@myseneca.ca
id: 127900223
date: 10/02/2023
*/
#ifndef SDDS_TOURNAMENT_H
#define SDDS_TOURNAMENT_H
#include "SoccerTeam.h"

namespace sdds
{
    class Tournament
    {
    private:
        char *m_name;                   // points to a dynamically allocated Cstring
        int m_num;                      // size of the dynamically allocated array of soccer team. It should be more then zero.
        SoccerTeam *m_soccer = nullptr; // pointer to the dynamically allocated array of soccerTeam
    public:
        Tournament();
        ~Tournament();
        void setTournament(const char *name, int noOfteam, const SoccerTeam *soccer);
        void setEmpty();
        bool isEmpty() const;
        Tournament &match(const SoccerTeam *ls);
        std::ostream &display() const;
        Tournament(const char *name, int noOfteam, const SoccerTeam *soccer);
    };
}
#endif