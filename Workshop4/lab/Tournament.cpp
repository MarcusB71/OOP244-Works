/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Marcus Brown
email: mbrown106@myseneca.ca
id: 127900223
date: 10/02/2023
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Tournament.h"
using namespace std;
namespace sdds
{
    Tournament::Tournament()
    {
        setEmpty();
    }
    Tournament::Tournament(const char *name, int noOfteam, const SoccerTeam *soccer)
    {
        setTournament(name, noOfteam, soccer);
    }
    void Tournament::setTournament(const char *name, int noOfteam, const SoccerTeam *soccer)
    {
        if (name == nullptr || noOfteam <= 0 || soccer == nullptr)
        {
            setEmpty();
        }
        else
        {
            m_num = noOfteam;
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
            m_soccer = new SoccerTeam[m_num];
            for (int i = 0; i < noOfteam; i++)
            {
                m_soccer[i].setTeam(soccer[i]);
            }
        }
    }
    void Tournament::setEmpty()
    {
        // delete[] m_name; //not sure if neccessary
        m_name = nullptr;
        m_num = 0;
        // delete[] m_soccer;
        m_soccer = nullptr;
    }
    bool Tournament::isEmpty() const
    {
        if (m_name != nullptr && m_soccer != nullptr && m_num > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Tournament &Tournament::match(const SoccerTeam *ls)
    {
        for (int i = 0; i < m_num; i++)
        {
            for (int j = i + 1; j < m_num; j++)
            {
                if (m_soccer[i].fouls() < m_soccer[j].fouls())
                {
                    m_soccer[j].setFine(m_soccer[j].returnFines(), m_soccer[j].fouls() * 2);

                    if (m_soccer[j].fouls() > MAX_FOUL)
                    {
                        m_soccer[j].setEmpty();
                    }

                    m_soccer[i].addGolas();
                }
                else
                {
                    m_soccer[i].setFine(m_soccer[i].returnFines(), m_soccer[i].fouls() * 2);

                    if (m_soccer[i].fouls() > MAX_FOUL)
                    {
                        m_soccer[i].setEmpty();
                    }

                    m_soccer[j].addGolas();
                }
            }
        }
        return *this;
    }
    std::ostream &Tournament::display() const
    {
        if (isEmpty())
        {
            cout << "Tournament name: " << m_name << endl;
            cout << "list of the teams" << endl;
            cout.width(45);
            cout.fill(' ');
            cout << "Fines";
            cout.width(10);
            cout.fill(' ');
            cout << "Fouls";
            cout.width(10);
            cout.fill(' ');
            cout << "Goals" << endl;

            for (int i = 0; i < m_num; i++)
            {
                cout << "Team[" << i + 1 << "] :";
                m_soccer[i].display() << endl;
            }
        }
        else
        {
            cout << "Invalid Tournament";
        }
        return cout;
    }
    Tournament::~Tournament()
    {
        delete[] m_name;
        delete[] m_soccer;
    }
};
