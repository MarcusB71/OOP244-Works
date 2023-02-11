/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Marcus Brown
email: mbrown106@myseneca.ca
id: 127900223
date: 09/02/2023
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "SoccerTeam.h"
using namespace std;
namespace sdds
{
    SoccerTeam::SoccerTeam()
    {
        setEmpty();
    }
    SoccerTeam::SoccerTeam(const char *tname, double fines, int foul)
    {
        setName(tname);
        setFine(fines, foul);
    }
    void SoccerTeam::setTeam(const SoccerTeam &team)
    {
        setName(team.m_teamName);
        setFine(team.m_fines, team.m_noFouls);
    }
    void SoccerTeam::setName(const char *tname)
    {
        strcpy(m_teamName, tname);
    }
    void SoccerTeam::setFine(double fines, int foul)
    {
        if (fines >= 0 && foul >= 0)
        {
            m_fines = fines;
            m_noFouls = foul;
        }
        else
        {
            setEmpty();
        }
    }
    void SoccerTeam::setEmpty()
    {
        m_teamName[0] = '\0';
        m_noFouls = -1;
        m_fines = -1.0;
        m_golas = 0;
    }
    bool SoccerTeam::isEmpty() const
    {
        if (m_teamName != nullptr && m_teamName[0] != '\0' && m_fines >= 0.0 && m_noFouls >= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void SoccerTeam::calFines()
    {
        m_fines += m_fines * .8;
    }
    double SoccerTeam::returnFines() // custom function
    {
        return m_fines += m_fines * .2;
    }
    void SoccerTeam::addGolas() // custom function
    {
        m_golas = m_golas + 1;
    }
    int SoccerTeam::fouls() const
    {
        return m_noFouls;
    }
    std::ostream &SoccerTeam::display() const
    {
        if (isEmpty())
        {
            cout.width(30);
            cout.setf(ios::left);
            cout.fill(' ');
            cout << m_teamName;
            cout.unsetf(ios::left);

            cout.width(6);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout.fill(' ');
            cout << m_fines;
            cout.unsetf(ios::fixed);

            cout.width(6);
            cout.precision(6);
            cout.fill(' ');
            cout << m_noFouls;

            cout.width(10);
            if (m_golas >= 1)
            {
                cout << m_golas << "w";
            }
            else
            {
                cout << m_golas;
            }
        }
        else
        {
            cout << "Invalid Team";
        }
        return cout;
    }
}