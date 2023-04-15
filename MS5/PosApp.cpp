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
    void PosApp::POS() {
        cout << ">>>> Starting Point of Sale.................................................." << endl;
        cout << "Running POS()" << endl;
    }
    void PosApp::printTitle(const char* title) {
        cout << ">>>> ";
        cout.setf(ios::left);
        cout.width(72);
        cout.fill('.');
        cout << title << endl;
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
        cout << "-----------------------------------------------^--------------^" << endl;

    }
}