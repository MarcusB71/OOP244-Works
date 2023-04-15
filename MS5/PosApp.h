#ifndef SDDS_POSAPP_H
#define SDDS_POSAPP_H
#include <iostream>
#include "POS.h"
#include "Item.h"
#include "Perishable.h"
#include "NonPerishable.h"
#include <fstream>
namespace sdds {
    class PosApp {
    private:
        char m_filename[129];
        Item* m_Iptr[MAX_NO_ITEMS];
        int m_nptr;
    public:
        PosApp(const char* filename = "");
        PosApp(const PosApp& app) = delete;
        PosApp& operator=(const PosApp& app) = delete;
        int menu(); //displays menu and receives user choice must be valid int
        void addItem();
        void removeItem();
        void stockItem();
        void listItems();
        void POS();
        void saveRecs();
        void loadRecs();
        void run();
        void printTitle(const char* title);
    };

}
#endif