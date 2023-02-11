/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Marcus Brown
email: mbrown106@myseneca.ca
id: 127900223
date: 10/02/2023
*/
#ifndef SDDS_SOCCERTEAM_H
#define SDDS_SOCCERTEAM_H
const int MAX_FOUL = 4; // maximum number of fouls

namespace sdds
{
    class SoccerTeam
    {
    private:
        char m_teamName[41]; // a statically allocated Cstring with size 41. Remember, name could be
                             // maximum 40 characters long and 1 byte is for the null byte.
        int m_noFouls;       // number of fouls, it can be zero or more but cannot be a negative number
        double m_fines;      // it can be equal to and more than zero.
        int m_golas;         // can be zero or more

    public:
        SoccerTeam();
        SoccerTeam(const char *tname, double fines, int foul);
        void setTeam(const SoccerTeam &team);
        void setName(const char *tname);
        void setFine(double fines, int foul);
        void addGolas();
        void setEmpty();
        bool isEmpty() const;
        void calFines();
        double returnFines();
        int fouls() const;
        std::ostream &display() const;
    };
}
#endif