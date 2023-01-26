#include "GPAList.h"
#include <iostream>
using namespace std;
namespace sdds
{

    GPA gpas[86];
    // loads all GPA into the global array of structures
    bool gpaQuery(const char *filename)
    {
        GPA studentGPA;
        int gpaNum = 0;

        bool ok = true;
        if (openFile(filename))
        {
            while (ok && gpaNum < 86)
            {
                ok = readName(studentGPA.name) &&
                     readStno(&studentGPA.stno) &&
                     readGPA(&studentGPA.gpa);
                if (ok)
                {
                    gpas[gpaNum++] = studentGPA;
                }
            }
            closeFile();
            promptUser(gpas);
        }
        return gpaNum == 86;
    }
    void sortData(struct GPA *studentGPA, int gpaNum)
    {
        int i = 0, j = 0;
        struct GPA gpaHolder;
        for (i = 0; i < gpaNum; i++)
        {
            if (studentGPA[i].stno)
            {
                for (j = 0; j < gpaNum - i - 1; j++)
                {
                    if (studentGPA[j].stno > studentGPA[j + 1].stno)
                    {
                        gpaHolder = studentGPA[j];
                        studentGPA[j] = studentGPA[j + 1];
                        studentGPA[j + 1] = gpaHolder;
                    }
                }
            }
        }
    }
    bool matchGPA(struct GPA *studentGPA, const char op[], double value)
    {
        bool found = false;

        if (strcmp(">", op) == 0)
        {
            if (studentGPA->gpa > value)
            {
                found = true;
            }
        }
        if (strcmp("<", op) == 0)
        {
            if (studentGPA->gpa < value)
            {
                found = true;
            }
        }
        if (strcmp("~", op) == 0)
        {
            if (studentGPA->gpa < value + 0.05 && studentGPA->gpa > value - 0.05)
            {
                found = true;
            }
        }
        return found;
    }

    void displayGPA(const GPA *studentGPA)
    {
        cout << studentGPA->stno << ": " << studentGPA->gpa << " (" << studentGPA->name << ")" << endl;
    }

    void displayMatchingGPAS(const char op[], double value)
    {
        int i, j;
        for (i = 0, j = 1; i < 86; i++)
        {
            if (matchGPA(&gpas[i], op, value))
            {
                cout << "[" << j++ << "] ";
                displayGPA(&gpas[i]);
            }
        }
        if (j == 1)
        {
            cout << "No match found for: " << op << value << endl;
        }
    }
}
