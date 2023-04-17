/* Citation and Sources...
Final Project Milestone 5
Module: PosApp
Filename: PosApp.h
Version 1.0
Author	Marcus Brown
Email: mbrown106@myseneca.ca
Id: 127900223
Date: 2023/04/15
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------*/
#ifndef SDDS_POSAPP_H
#define SDDS_POSAPP_H
#include <iostream>
#include "POS.h"
#include "Item.h"
#include "Perishable.h"
#include "NonPerishable.h"
#include "Bill.h"
#include <fstream>
namespace sdds {
    class PosApp {
    private:
        char m_filename[129];
        Item* m_Iptr[MAX_NO_ITEMS];
        int m_nptr;
        Bill m_bill;
    public:
        PosApp(const char* filename = "");
        ~PosApp();
        PosApp(const PosApp& app) = delete;
        PosApp& operator=(const PosApp& app) = delete;
        int menu();
        void addItem();
        void removeItem();
        void stockItem();
        void listItems();
        int selectItem();
        void POS();
        void saveRecs();
        void loadRecs();
        void run();
        void printTitle(const char* title);
        int search(int sku);
    };

}
#endif