#include "UI.h"
#include <iostream>
#include <string>
using namespace std;
namespace sdds
{
    void promptUser(struct GPA gpas[])
    {
        char op[20];
        char tempString[20];
        double value = 0.0;
        int finished = 0;
        sortData(gpas, 86);
        cout << "Enter GPA query..." << endl;
        cout << "? ";

        cin >> tempString;
        op[0] = tempString[0];
        op[1] = '\0';
        if (tempString[3])
        {
            tempString[0] = tempString[1];
            tempString[1] = tempString[2];
            tempString[2] = tempString[3];
            tempString[3] = '\0';
            value = stod(tempString);
        }
        else if (tempString[1])
        {
            tempString[0] = tempString[1];
            tempString[1] = '\0';
            value = stod(tempString);
        }
        strcpy(tempString, "");

        while (!finished)
        {
            if (strcmp(op, ">") != 0 && strcmp(op, "<") != 0 && strcmp(op, "~") != 0 && strcmp(op, "!") != 0)
            {
                cout << "Syntax error: ? [Op][value]<ENTER>" << endl;
                cout << "Op:[>,<,~,!]" << endl;
                cout << "value: GPA value" << endl;
                cout << endl;
                cout << "? ";
                cin >> tempString;

                op[0] = tempString[0];
                op[1] = '\0';
                if (tempString[3])
                {
                    tempString[0] = tempString[1];
                    tempString[1] = tempString[2];
                    tempString[2] = tempString[3];
                    tempString[3] = '\0';
                    value = stod(tempString);
                }
                else if (tempString[1])
                {
                    tempString[0] = tempString[1];
                    tempString[1] = '\0';
                    value = stod(tempString);
                }
                strcpy(tempString, "");
            }
            if (strcmp(op, "!") == 0)
            {
                cout << "Exit the program? (Y)es/(N)o: ";
                cin >> op;
                if (strcmp(op, "y") == 0 || strcmp(op, "Y") == 0)
                {
                    cout << "Goodbye!";
                    finished = 1;
                }
            }
            else
            {
                displayMatchingGPAS(op, value);
                cout << "? ";
                cin >> tempString;

                op[0] = tempString[0];
                op[1] = '\0';
                if (tempString[3])
                {
                    tempString[0] = tempString[1];
                    tempString[1] = tempString[2];
                    tempString[2] = tempString[3];
                    tempString[3] = '\0';
                    value = stod(tempString);
                }
                else if (tempString[1])
                {
                    tempString[0] = tempString[1];
                    tempString[1] = '\0';
                    value = stod(tempString);
                }
                strcpy(tempString, "");
            }
        }
    }
}