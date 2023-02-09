#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Toys.h"
#include "Store.h"
using namespace std;
namespace sdds
{
    Toys::Toys()
    {
        m_tname[0] = '\0'; // toy name, up to MAX_TNAME size
        m_sku = {};        // SKU number, maximum 8 digits long
        m_price = {};      // toy price
        m_age = {};        // toy according to age group
        m_onSale = {};     // keep track, if toys are on sale or not
    }
    void Toys::setEmpty()
    {
        m_tname[0] = '\0';
        m_sku = {};
        m_price = {};
        m_age = {};
        m_onSale = {};
    }
    void Toys::addToys(const char *tname, int sku, double price, int age)
    {
        if (tname != nullptr && strlen(tname) < MAX_TNAME && sku < 100000000 && sku > 9999999 && price > 0)
        {
            strcpy(m_tname, tname);
            m_sku = sku;
            m_price = price;
            m_age = age;
        }
        else
        {
            setEmpty();
        }
    }
    void Toys::isSale(bool sale)
    {
        m_onSale = sale;
    }
    void Toys::calSale()
    {
        m_price = m_price - (m_price * 0.2);
    }
    bool Toys::compareSKU(int sku)
    {
        return sku == m_sku && !m_onSale;
    }
    void Toys::display() const
    {
        if (m_tname[0] != '\0')
        {
            cout.setf(ios::left);
            cout.width(15);
            cout.fill(' ');
            cout << m_tname;
            cout.unsetf(ios::left);
            cout.setf(ios::right);
            cout.width(10);
            cout << m_sku;
            cout.width(6);
            cout << m_age;
            cout.unsetf(ios::right);
            cout.setf(ios::fixed);
            cout.width(12);
            cout.precision(2);
            cout << m_price;
            cout.unsetf(ios::fixed);
            if (m_onSale)
            {
                cout.width(10);
                cout << "On Sale";
                cout << " " << endl;
            }
            else
            {
                cout.width(8);
                cout << " " << endl;
            }
        }
        else
        {
            cout << "Invalid Toy" << endl;
        }
    }
}