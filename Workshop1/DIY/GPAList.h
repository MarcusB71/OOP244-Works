#ifndef _SDDS_GPALIST_H
#define _SDDS_GPALIST_H
#include "File.h"
using namespace std;
namespace sdds
{
    bool gpaQuery(const char *filename);
    bool matchGPA(const GPA *studentGPA, const char op[], double value);
    void displayMatchingGPAS(const char op[], double value);
    void displayGPA(const GPA *studentGPA);
    void promptUser();
}
#endif