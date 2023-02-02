#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Customer.h"
#include "Tools.h"
namespace sdds
{
    // complete
    void read(char *str, int len)
    { // Fully provided
        if (cin.peek() == '\n')
        {
            cin.ignore();
        }
        cin.getline(str, len);
    }
    // complete

    void EmptyRecord(Customers &c_rec)
    {
        c_rec = {};
    }
    void EmptyRecord(CustomersRecord &t_rec)
    {
        t_rec = {};
    }
    bool read(Customers &rec)
    {
        cout << " Enter User name: ";
        read(rec.user_name, 21);
        if (strcmp(rec.user_name, "") == 0)
        {
            return false;
        }
        cout << " Enter likes_count: ";
        cin >> rec.likes_count;
        cout << " Enter retweets_count: ";
        cin >> rec.retweets_count;
        cout << " Enter replies_count: ";
        cin >> rec.replies_count;
        cout << " Enter share videos (y/n): ";
        cin >> rec.share_videos;
        return true;
    }
    void addCustomer(CustomersRecord &t_rec, const Customers &c_rec)
    {
        if (t_rec.noOfRecords == 0)
        {
            t_rec.ptr_rec = new Customers[t_rec.noOfRecords + 1];
            t_rec.ptr_rec[0] = c_rec;
        }
        else
        {
            Customers *tempCustomer = new Customers[t_rec.noOfRecords + 1];
            for (int i = 0; i < t_rec.noOfRecords; i++)
            {
                tempCustomer[i] = t_rec.ptr_rec[i];
            }
            tempCustomer[t_rec.noOfRecords] = c_rec;
            delete[] t_rec.ptr_rec;
            t_rec.ptr_rec = nullptr;
            t_rec.ptr_rec = tempCustomer;
            // delete[] tempCustomer;
        }

        t_rec.noOfRecords++;
    }
    void display(const Customers &c_rec)
    {
        cout << c_rec.user_name << ", " << c_rec.likes_count << ", " << c_rec.retweets_count << ", " << c_rec.replies_count << ", " << c_rec.share_videos << "\n";
    }
    void display(const CustomersRecord &t_rec)
    {
        for (int i = 0; i < t_rec.noOfRecords; i++)
        {
            cout << i + 1 << ". ";
            display(t_rec.ptr_rec[i]);
            cout << endl;
        }
    }

}
