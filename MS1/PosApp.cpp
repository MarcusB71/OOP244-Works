/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Marcus Brown
email: mbrown106@myseneca.ca
id: 127900223
date: 13/03/2023
*/
#define _CRT_SECURE_NO_WARNINGS
#include "PosApp.h"
#include <iostream>
#include <cstring>

using namespace std;
namespace sdds {
    PosApp::PosApp(const char* filename) {
        strcpy(m_filename, filename);
    }
    int PosApp::menu() {
        int selection;
        cout << "The Sene-Store" << endl;
        cout << "1- List items" << endl;
        cout << "2- Add item" << endl;
        cout << "3- Remove item" << endl;
        cout << "4- Stock item" << endl;
        cout << "5- Point of Sale" << endl;
        cout << "0- exit program" << endl;
        cout << "> ";
        cin >> selection;
        while (cin.fail() || selection > 5 || selection < 0)
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(9999, '\n');
                cout << "Invalid Integer, try again: ";
            }
            else {
                cin.clear();
                cin.ignore(9999, '\n');
                cout << "[0<=value<=5], retry: > ";
            }
            cin >> selection;
        }
        return selection;
    }
    void PosApp::run() {
        int selection = 1;
        loadRecs();
        while (selection)
        {
            selection = menu();
            switch (selection)
            {
            case 0:
                saveRecs();
                cout << "Goodbye!" << endl;
                break;
            case 1:
                listItems();
                break;
            case 2:
                addItem();
                break;
            case 3:
                removeItem();
                break;
            case 4:
                stockItem();
                break;
            case 5:
                POS();
                break;
            default:
                break;
            }
        }
    }
    void PosApp::addItem() {
        cout << ">>>> Adding Item to the store................................................" << endl;
        cout << "Running addItem()" << endl;
    }
    void PosApp::removeItem() {
        cout << ">>>> Remove Item............................................................." << endl;
        cout << "Running removeItem()" << endl;
    }
    void PosApp::stockItem() {
        cout << ">>>> Select an item to stock................................................." << endl;
        cout << "Running stockItem()" << endl;
    }
    void PosApp::listItems() {
        cout << ">>>> Listing Items..........................................................." << endl;
        cout << "Running listItems()" << endl;
    }
    void PosApp::POS() {
        cout << ">>>> Starting Point of Sale.................................................." << endl;
        cout << "Running POS()" << endl;
    }
    void PosApp::saveRecs() {
        cout << ">>>> Saving Data............................................................." << endl;
        cout << "Saving data in " << m_filename << endl;
    }
    void PosApp::loadRecs() {
        cout << ">>>> Loading Items..........................................................." << endl;
        cout << "Loading data from " << m_filename << endl;
    }
}