/* Citation and Sources...
Final Project Milestone 5
Module: PosApp
Filename: PosApp.cpp
Version 1.0
Author	Marcus Brown
Email: mbrown106@myseneca.ca
Id: 127900223
Date: 2023/04/15
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "PosApp.h"
#include <cstring>
using namespace std;
namespace sdds {
    PosApp::PosApp(const char* filename) {
        m_nptr = 0;
        if (filename && strlen(filename) <= 128)
        {
            strncpy(m_filename, filename, 128);
            m_filename[128] = '\0';
        }
        for (int i = 0; i < MAX_NO_ITEMS; i++)
        {
            m_Iptr[i] = nullptr;
        }
    }
    PosApp::~PosApp() {
        for (int i = 0; i < m_nptr; i++)
        {
            delete m_Iptr[i];
            m_Iptr[i] = nullptr;
        }
        m_nptr = 0;
    }
    int PosApp::menu() {
        int selection;
        cout << "The Sene-Store" << endl;
        cout << "1- List items" << endl;
        cout << "2- Add item" << endl;
        cout << "3- Remove item" << endl;
        cout << "4- Stock item" << endl;
        cout << "5- POS" << endl;
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
        printTitle("Adding Item to the store");
        if (m_Iptr[MAX_NO_ITEMS - 1] != nullptr)
        {
            cout << "Inventory Full!" << endl;

        }
        else {
            Item* temp{};
            char itemType;
            cout << "Is the Item perishable? (Y)es/(N)o: ";
            cin >> itemType;
            bool finished = false;
            while (!finished)
            {
                if (itemType == 'y')
                {
                    temp = new Perishable();
                    temp->read(cin);
                    if (cin) {
                        m_Iptr[m_nptr++] = temp;
                        printTitle("DONE!");
                        finished = true;
                    }
                    else {
                        cin.clear();
                        cin.ignore(9999, '\0');
                        cout << temp;
                        cout << ", try again..." << endl;
                    }
                }
                else if (itemType == 'n') {
                    temp = new NonPerishable();
                    temp->read(cin);
                    if (cin)
                    {
                        m_Iptr[m_nptr++] = temp;
                        printTitle("DONE!");
                        finished = true;
                    }
                    else {
                        cin.clear();
                        cin.ignore(9999, '\0');
                        cout << temp;
                        cout << ", try again..." << endl;

                    }
                }
                else {
                    cout << "invalid input";
                }
            }
        }
    }
    void PosApp::removeItem() {
        printTitle("Remove Item");
        int row = selectItem();
        cout << "Removing...." << endl;
        m_Iptr[row - 1]->displayType(2);
        cout << *m_Iptr[row - 1];
        delete m_Iptr[row - 1];
        for (int i = row - 1; i < m_nptr - 1; i++)
        {
            m_Iptr[i] = m_Iptr[i + 1];
        }
        m_nptr--;
        printTitle("DONE!");
    }
    void PosApp::stockItem() {
        printTitle("Select an item to stock");
        int row = selectItem();
        cout << "Selected Item:" << endl;
        m_Iptr[row - 1]->displayType(2);
        cout << *m_Iptr[row - 1];
        cout << "Enter quantity to add: ";
        bool finished = false;
        char qtyToAdd[20];
        bool valid = true;
        while (!finished)
        {
            valid = true;
            cin >> qtyToAdd;
            int length = strlen(qtyToAdd);
            for (int i = 0; i < length; i++)
            {
                if (!isdigit(qtyToAdd[i]) && qtyToAdd[i] != '-') {
                    valid = false;
                }
            }
            if (!valid)
            {
                cout << "Invalid Integer, try again: ";
            }
            else if (cin.fail() || atoi(qtyToAdd) < 1 || atoi(qtyToAdd) > MAX_STOCK_NUMBER - m_Iptr[row - 1]->quantity())
            {
                cout << "[1<=value<=" << MAX_STOCK_NUMBER - m_Iptr[row - 1]->quantity() << "], retry: Enter quantity to add: ";
            }
            else {
                finished = true;
            }
        }
        *m_Iptr[row - 1] += atoi(qtyToAdd);
        printTitle("DONE!");
    }
    void PosApp::POS() {
        printTitle("Starting Point of Sale");
        bool finished = false;
        char SKU[MAX_SKU_LEN + 1];
        int index = 0;
        cin.ignore();
        while (!finished)
        {
            cout << "Enter SKU or <ENTER> only to end sale..." << endl;
            cout << "> ";
            cin.getline(SKU, MAX_SKU_LEN + 1);
            if (SKU[0] == '\0')
            {
                finished = true;
            }
            else {
                if (SKU != nullptr && !cin.fail())
                {
                    index = search(atoi(SKU));
                    if (index > 0)
                    {
                        if (m_Iptr[index]->quantity() > 0)
                        {
                            *m_Iptr[index] -= 1;
                            m_bill.add(m_Iptr[index]);
                            m_Iptr[index]->displayType(2);
                            cout << *m_Iptr[index];
                            cout << endl;
                            cout << ">>>>> Added to bill" << endl;
                            cout << ">>>>> Total: <";
                            cout.setf(ios::fixed);
                            cout.precision(2);
                            cout << m_bill.total() << ">" << endl;
                            cout.unsetf(ios::fixed);
                        }
                        else {
                            cout << "Item out of stock" << endl;
                            m_Iptr[index]->clear();
                        }
                    }
                    else {
                        cout << "!!!!! Item Not Found !!!!!" << endl;
                    }
                }
                else {
                    cin.clear();
                    cin.ignore(9999, '\n');
                }
            }
        }
        m_bill.print(cout);
    }
    int PosApp::search(int sku) {
        int index = -1;
        for (int i = 0; i < m_nptr; i++)
        {
            if (atoi(m_Iptr[i]->getSKU()) == sku)
            {
                index = i;
            }
        }
        return index;
    }
    void PosApp::printTitle(const char* title) {
        cout << ">>>> ";
        cout.setf(ios::left);
        cout.width(72);
        cout.fill('.');
        cout << title;
        cout << endl;
        cout.unsetf(ios::left);
    }
    void PosApp::loadRecs() {
        printTitle("Loading Items");
        ifstream input(m_filename);
        if (!input)
        {
            ofstream output(m_filename);
            output.close();
            input.open(m_filename);
        }
        for (int i = 0; i < m_nptr; i++)
        {
            delete[] m_Iptr[i];
            m_nptr = 0;
        }
        char temp;
        while (input && m_nptr < MAX_NO_ITEMS)
        {
            temp = 'Z';
            input >> temp;
            Item* item = nullptr;
            if (temp == 'P')
            {
                item = new Perishable();
                if (item)input >> *item;
                m_Iptr[m_nptr++] = item;
            }
            if (temp == 'N')
            {
                item = new NonPerishable();
                if (item)input >> *item;
                m_Iptr[m_nptr++] = item;
            }
        }
    }
    void PosApp::saveRecs() {
        printTitle("Saving Data");
        ofstream ofstr(m_filename);
        for (int i = 0; i < m_nptr; i++)
        {
            ofstr << *m_Iptr[i] << endl;
        }
    }
    int PosApp::selectItem() {
        printTitle("Item Selection by row number");
        cout << "Press <ENTER> to start....";
        cin.ignore();
        cin.get();
        printTitle("Listing Items");
        Item* temp{};
        for (int i = 0; i < m_nptr - 1; i++)
        {
            for (int j = 0; j < m_nptr - i - 1; j++)
            {
                if (strcmp(m_Iptr[j]->getName(), m_Iptr[j + 1]->getName()) > 0)
                {
                    temp = m_Iptr[j];
                    m_Iptr[j] = m_Iptr[j + 1];
                    m_Iptr[j + 1] = temp;
                }
            }
        }
        cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |" << endl;
        cout << "-----|--------|--------------------|-------|---|----|---------|-------------|" << endl;
        for (int i = 0; i < m_nptr; i++)
        {
            m_Iptr[i]->displayType(POS_LIST);
            cout.width(4);
            cout.fill(' ');
            cout.setf(ios::right);
            cout << i + 1 << " | ";
            cout.unsetf(ios::right);
            cout << *m_Iptr[i] << endl;
        }
        cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;
        bool finished = false;
        cout << "Enter the row number: ";
        int rowNum = 0;
        while (!finished)
        {
            cin >> rowNum;
            if (cin.fail() || rowNum < 1 || rowNum > m_nptr)
            {
                cin.clear();
                cin.ignore(9999, '\n');
                if (rowNum == 0)
                {
                    cout << "Invalid Integer, try again: ";
                }
                else {
                    cout << "[1<=value<=" << m_nptr << "], retry: Enter the row number: ";
                }
            }
            else {
                finished = true;
            }
        }
        return rowNum;
    }
    void PosApp::listItems() {
        printTitle("Listing Items");
        Item* temp{};
        for (int i = 0; i < m_nptr - 1; i++)
        {
            for (int j = 0; j < m_nptr - i - 1; j++)
            {
                if (strcmp(m_Iptr[j]->getName(), m_Iptr[j + 1]->getName()) > 0)
                {
                    temp = m_Iptr[j];
                    m_Iptr[j] = m_Iptr[j + 1];
                    m_Iptr[j + 1] = temp;
                }
            }
        }
        cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |" << endl;
        cout << "-----|--------|--------------------|-------|---|----|---------|-------------|" << endl;
        double totalAsset = 0.0;
        for (int i = 0; i < m_nptr; i++)
        {
            m_Iptr[i]->displayType(POS_LIST);
            cout.width(4);
            cout.fill(' ');
            cout.setf(ios::right);
            cout << i + 1 << " | ";
            cout.unsetf(ios::right);
            cout << *m_Iptr[i] << endl;

            totalAsset += m_Iptr[i]->cost() * m_Iptr[i]->quantity();
        }
        cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;
        cout << "                               Total Asset: $  | ";
        cout.width(12);
        cout.fill(' ');
        cout.setf(ios::right);
        cout << totalAsset << " |" << endl;
        cout.unsetf(ios::right);
        cout << "-----------------------------------------------^--------------^" << endl;
        cout << endl;
    }
}