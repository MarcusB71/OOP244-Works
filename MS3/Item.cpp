#define _CRT_SECURE_NO_WARNINGS
#include "Item.h"
#include <cstring>
using namespace std;
namespace sdds {
    Item::Item() {
        setEmpty();
    }
    void Item::setEmpty() {
        m_SKU[0] = '\0';
        m_name = nullptr;
        m_price = -1;
        m_taxed = false;
        m_quantity = -1;
        m_displayFlag = 0;
        m_error.clear();
    }
    Item::Item(const Item& item) {
        setEmpty();
        operator=(item);
    }
    Item& Item::operator=(const Item& item) {
        if (this != &item) {
            strcpy(m_SKU, item.m_SKU);
            if (m_name)delete[]m_name;
            m_name = new char[strlen(item.m_name) + 1];
            strcpy(m_name, item.m_name);
            m_price = item.m_price;
            m_taxed = item.m_taxed;
            m_quantity = item.m_quantity;
            m_displayFlag = item.m_displayFlag;
            m_error = item.m_error;
        }
        return *this;
    }
    Item::~Item() {
        delete[]m_name;
        m_name = nullptr;
    }
    bool Item::operator==(const char* string) const {
        return !strcmp(m_SKU, string);
    }
    bool Item::operator>(const Item& item) const {
        return strcmp(m_name, item.m_name) > 0;
    }
    int Item::operator+=(int value) {
        if (m_quantity + value > MAX_STOCK_NUMBER) {
            m_quantity = MAX_STOCK_NUMBER;
            m_error = ERROR_POS_QTY;
        }
        else {
            m_quantity += value;
        }
        return m_quantity;
    }
    int Item::operator-=(int value) {
        if (value > m_quantity)
        {
            m_quantity = 0;
            m_error = ERROR_POS_STOCK;
        }
        else {
            m_quantity -= value;
        }
        return m_quantity;
    }
    Item::operator bool()const {
        return !m_error;
    }
    double Item::cost()const {
        return m_taxed ? m_price + m_price * TAX : m_price;
    }
    int Item::quantity()const {
        return m_quantity;
    }
    double& operator+=(double& dValue, const Item& item) {
        dValue += (item.cost() * item.quantity());
        return dValue;
    }
    Item& Item::displayType(int type) {
        m_displayFlag = type;
        return *this;
    }
    Item& Item::clear() {
        m_error.clear();
        return *this;
    }
    ostream& Item::write(ostream& ostr)const {
        if (m_error)
        {
            ostr << m_error;
        }
        else {
            if (m_displayFlag == POS_LIST)
            {
                ostr.setf(ios::left);
                ostr.width(7);
                ostr << m_SKU;
                ostr << "|";

                char name[21]{};
                strncpy(name, m_name, 20);
                ostr.width(20);
                ostr << name;
                ostr.unsetf(ios::left);
                ostr << "|";

                ostr.width(7);
                ostr.setf(ios::fixed);
                ostr.precision(2);
                ostr << m_price << "| ";
                ostr.unsetf(ios::fixed);

                if (m_taxed)
                {
                    ostr << "X";
                }
                else {
                    ostr << " ";
                }

                ostr << " | ";
                ostr.width(3);
                ostr << m_quantity << "| ";

                ostr.width(8);
                ostr.setf(ios::fixed);
                ostr.precision(2);
                ostr << cost() * m_quantity << "|";

            }
            else {
                ostr << "=============v" << endl;
                ostr << "Name:        " << m_name << endl;
                ostr << "Sku:         " << m_SKU << endl;
                ostr << "Price:       ";
                ostr.setf(ios::fixed);
                ostr.precision(2);
                ostr << m_price << endl;
                ostr.unsetf(ios::fixed);
                ostr << "Price + tax: ";
                if (m_taxed)
                {
                    ostr.setf(ios::fixed);
                    ostr.precision(2);
                    ostr << cost() << endl;
                    ostr.unsetf(ios::fixed);
                }
                else {
                    ostr << "N/A" << endl;
                }
                ostr << "Stock Qty:   " << m_quantity << endl;
            }
        }
        return ostr;
    }
    ofstream& Item::save(ofstream& ofstr)const {
        if (m_error)
        {
            cerr << m_error << endl;
        }
        else {
            ofstr.setf(ios::fixed);
            ofstr.precision(2);
            ofstr << itemType() << ',' << m_SKU << ',' << m_name << ',' << m_price << ',' << m_taxed << ',' << m_quantity;
        }
        return ofstr;
    }
    istream& Item::read(istream& istr) {
        char sku[100]{};
        cout << "Sku" << endl << "> ";
        istr >> sku;
        while (istr.fail() || strlen(sku) > MAX_SKU_LEN)
        {
            cout << ERROR_POS_SKU << endl << "> ";
            istr.clear();
            istr.ignore(999, '\n');
            istr >> sku;
        }
        istr.ignore(999, '\n');
        strcpy(m_SKU, sku);

        cout << "Name" << endl << "> ";
        char name[200]{};
        if (m_name)delete[] m_name;
        m_name = nullptr;
        istr.getline(name, 200);
        while (strlen(name) > MAX_NAME_LEN)
        {
            cout << ERROR_POS_NAME << endl << "> ";
            istr.getline(name, 200);
        }
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);

        cout << "Price" << endl << "> ";
        istr >> m_price;
        while (istr.fail() || m_price < 0)
        {
            cout << ERROR_POS_PRICE << endl << "> ";
            istr.clear();
            istr.ignore(999, '\n');
            istr >> m_price;
        }

        cout << "Taxed?" << endl << "(Y)es/(N)o: ";
        char taxed;
        istr >> taxed;
        while (taxed != 'y' && taxed != 'n')
        {
            cout << "Only 'y' and 'n' are acceptable: ";
            istr.clear();
            istr.ignore(999, '\n');
            istr >> taxed;
        }
        m_taxed = taxed == 'y' ? true : false;

        cout << "Quantity" << endl << "> ";
        istr >> m_quantity;
        while (istr.fail() || m_quantity <= 0 || m_quantity > MAX_STOCK_NUMBER)
        {
            cout << ERROR_POS_QTY << endl << "> ";
            istr.clear();
            istr.ignore(999, '\n');
            istr >> m_quantity;
        }
        return istr;
    }
    ifstream& Item::load(ifstream& ifstr) {
        m_error.clear();
        char sku[20]{};
        char name[100]{};
        double price{};
        char taxed{};
        int quantity{};
        ifstr.getline(sku, 20, ',');
        ifstr.getline(name, 100, ',');
        ifstr >> price;
        ifstr.ignore();
        ifstr >> taxed;
        ifstr.ignore();
        ifstr >> quantity;
        if (!ifstr.fail())
        {
            if (strlen(sku) > MAX_SKU_LEN)
            {
                m_error = ERROR_POS_SKU;
            }
            else if (strlen(name) > MAX_NAME_LEN)
            {
                m_error = ERROR_POS_NAME;
            }
            else if (price < 0)
            {
                m_error = ERROR_POS_PRICE;
            }
            else if (taxed != '1' && taxed != '0')
            {
                m_error = ERROR_POS_TAX;
            }
            else if (quantity < 0 || quantity > MAX_STOCK_NUMBER)
            {
                m_error = ERROR_POS_QTY;
            }
            else {
                strcpy(m_SKU, sku);
                if (m_name) delete[] m_name;
                m_name = new char[strlen(name) + 1];
                strcpy(m_name, name);
                m_price = price;
                m_taxed = taxed == '0' ? false : true;
                m_quantity = quantity;
            }
        }
        return ifstr;
    }
    ostream& Item::bprint(ostream& ostr)const {
        ostr << "| ";
        ostr.width(20);
        ostr.fill(' ');
        ostr.setf(ios::left);
        char name[21]{};
        strncpy(name, m_name, 20);
        ostr << name;
        ostr.unsetf(ios::left);
        ostr << "|";
        ostr.width(10);
        ostr.setf(ios::fixed);
        ostr.precision(2);
        ostr << cost() << "|  ";
        if (m_taxed)
        {
            ostr << "T";
        }
        else {
            ostr << " ";
        }
        ostr << "  |" << endl;
        return ostr;
    }
}