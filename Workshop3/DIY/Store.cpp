#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Store.h"
using namespace std;
namespace sdds
{
    void Store::setStore(const char *sName, int no)
    {
        setEmpty();
        if (sName[0] != '\0' && strlen(sName) < MAX_SNAME && no > 0 && no <= MAX_NUM_TOYS)
        {
            strcpy(m_sName, sName);
            m_noOfToys = no;
        }
    }

    void Store::setToys(const char *tname, int sku, double price, int age)
    {
        if (m_addToys < m_noOfToys)
        {
            m_toy[m_addToys].addToys(tname, sku, price, age);
            m_addToys++;
        }
    }

    void Store::display() const
    {
        if (m_sName[0] != '\0')
        {
            cout.fill('*');
            cout.width(60);
            cout << "*" << endl;
            cout << m_sName << endl;
            cout.fill('*');
            cout.width(60);
            cout << "*" << endl;
            cout << "list of the toys" << endl;
            cout.fill(' ');
            cout.width(30);
            cout << "SKU";
            cout.fill(' ');
            cout.width(10);
            cout << "Age";
            cout.fill(' ');
            cout.width(11);
            cout << "Price";
            cout.fill(' ');
            cout.width(10);
            cout << "Sale" << endl;
            for (int i = 0; i < m_addToys; i++)
            {
                cout << "Toy[" << i + 1 << "] :";
                m_toy[i].display();
            }
        }
        else
        {
            cout << "Invalid Store" << endl;
        }
    }

    void Store::find(int sku)
    {
        for (int i = 0; i < m_addToys; i++)
        {
            if (m_toy[i].compareSKU(sku))
            {
                m_toy[i].isSale(true);
                m_toy[i].calSale();
            }
        }
    }

    void Store::setEmpty()
    {
        m_sName[0] = '\0'; // Store name, up to MAX_SNAME size
        m_noOfToys = {};   // No of toys;
        m_addToys = {};    // no of toys added
        for (int i = 0; i < MAX_NUM_TOYS; i++)
        {
            m_toy[i] = Toys();
        }
    }
}