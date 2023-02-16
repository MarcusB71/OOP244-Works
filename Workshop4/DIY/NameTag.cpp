/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Marcus Brown
email: mbrown106@myseneca.ca
id: 127900223
date: 15/02/2023
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "NameTag.h"
using namespace std;
namespace sdds
{
    NameTag::NameTag()
    {
        setEmpty();
    }
    NameTag::NameTag(const char *name)
    {
        setEmpty();
        if (name)
        {
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
        }
    }
    NameTag::NameTag(const char *name, int extention)
    {
        setEmpty();
        if (name)
        {
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
        }
        m_extensionNum = extention;
    }
    void NameTag::setEmpty()
    {
        // delete[] m_name; //why is it bad that i delete m_name here ask prof (thought delete has built in detection)
        m_name = nullptr;
        m_extensionNum = 0;
    }
    NameTag::~NameTag()
    {
        delete[] m_name;
        m_name = nullptr;
    }
    NameTag &NameTag::read()
    {
        int phoneExt = 0;
        bool extProblem = true;
        bool optionProblem = true;
        char desireExt;
        char tempName[41];
        cout << "Please enter the name: ";
        cin.get(tempName, 41, '\n');
        cin.clear();
        cin.ignore(10000, '\n');
        setEmpty();
        m_name = new char[strlen(tempName) + 1];
        strcpy(m_name, tempName);
        if (m_name == nullptr || m_name[0] == '\0')
        {
            cout << "EMPTY NAMETAG!" << endl;
        }
        else
        {
            cout << "Would you like to enter an extension? (Y)es/(N)o: ";
            while (optionProblem)
            {
                cin >> desireExt;
                cin.clear();
                cin.ignore(10000, '\n');
                if (desireExt == 'Y' || desireExt == 'y' || desireExt == 'N' || desireExt == 'n')
                {
                    optionProblem = false;
                    if (desireExt == 'Y' || desireExt == 'y')
                    {
                        cout << "Please enter a 5 digit phone extension: ";
                        while (extProblem)
                        {
                            extProblem = false;
                            cin >> phoneExt;
                            cin.clear();
                            cin.ignore(10000, '\n');
                            if (cin.fail() || !phoneExt)
                            {
                                cout << "Bad integer, try again: ";
                                extProblem = true;
                            }
                            else if (phoneExt > MAX_EXT_VALUE || phoneExt < MIN_EXT_VALUE)
                            {
                                cout << "Invalid value [10000<=value<=99999]: ";
                                extProblem = true;
                            }
                        }
                    }
                }
                else
                {
                    cout << "Only (Y) or (N) are acceptable, try again: ";
                    optionProblem = true;
                }
            }
        }
        m_extensionNum = phoneExt;
        return *this;
    }
    std::ostream &NameTag::print() const
    {
        int width = 0;
        if (m_name == nullptr || (m_extensionNum != 0 && (m_extensionNum < MIN_EXT_VALUE || m_extensionNum > MAX_EXT_VALUE)))
        {
            cout << "EMPTY NAMETAG!" << endl;
        }
        else
        {
            int len = strlen(m_name);
            if (len >= MAX_NAME_LENGTH)
            {
                width = MAX_NAME_LENGTH;
            }
            else
            {
                width = len;
            }
            // line 1
            cout << "+";
            cout.width(len < MIN_NAME_LENGTH ? 20 + 3 : width + 3);
            cout.fill('-');
            cout.setf(ios::right);
            cout << "+" << endl;
            // line 2
            cout.setf(ios::left);
            cout << "|";
            cout.width(len < MIN_NAME_LENGTH ? 20 + 3 : width + 3);
            cout.fill(' ');
            cout.setf(ios::right);
            cout << "|" << endl;
            // line 3
            cout.setf(ios::left);
            cout << "| ";
            for (int i = 0; i < len && i < MAX_NAME_LENGTH; i++)
            {
                cout << m_name[i];
            }
            cout.width(len < MIN_NAME_LENGTH ? 20 - len + 2 : 0);
            cout.fill(' ');
            cout << " |" << endl;
            // line 4
            cout.setf(ios::left);
            cout << "|";
            cout.width(len < MIN_NAME_LENGTH ? 20 + 3 : width + 3);
            cout.fill(' ');
            cout.setf(ios::right);
            cout << " |" << endl;
            // line 5
            cout << "| Extension: ";
            if (m_extensionNum == 0)
            {
                cout << "N/A";
                cout.width(len < MIN_NAME_LENGTH ? 20 - 11 + 2 - 3 : width - 11 - 1);
            }
            else
            {
                cout << m_extensionNum;
                cout.width(len < MIN_NAME_LENGTH ? 20 - 11 + 2 - 5 : width - 11 - 1);
            }
            cout.fill(' ');
            cout << "|" << endl;
            // line 6
            cout.setf(ios::left);
            cout << "|";
            cout.width(len < MIN_NAME_LENGTH ? 20 + 3 : width + 3);
            cout.fill(' ');
            cout.setf(ios::right);
            cout << " |" << endl;
            // line 7
            cout << "+";
            cout.width(len < MIN_NAME_LENGTH ? 20 + 3 : width + 3);
            cout.fill('-');
            cout.setf(ios::right);
            cout << "+" << endl;
        }
        return cout;
    }
}