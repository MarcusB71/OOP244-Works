#include "UI.h"
#include <iostream>
#include <cstring>
// #include <sstream>
using namespace std;
namespace sdds
{
    void promptUser()
    {
        char op[20];
        // string input;
        double value = 0.0;
        int finished = 0;
        cout << "Enter GPA query..." << endl;
        cout << "? ";
        cin >> op >> value;
        // cin >> input;
        // stringstream ss(input);
        // ss >> op;
        // ss.ignore();
        // ss >> value;

        while (!finished)
        {
            if (strcmp(op, ">") != 0 && strcmp(op, "<") != 0 && strcmp(op, "~") != 0 && strcmp(op, "!") != 0)
            {
                cout << "Syntax error: ? [Op][value]<ENTER>" << endl;
                cout << "Op:[>,<,~,!]" << endl;
                cout << "value: GPA value" << endl;
                cout << endl;
                cout << "? ";
                cin >> op >> value;
                // cin >> input;
                // ss >> op;
                // ss.ignore();
                // ss >> value;
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
                cin >> op >> value;
            }
        }
    }

}