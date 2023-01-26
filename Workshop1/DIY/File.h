#ifndef SDDS_FILE_H
#define SDDS_FILE_H
#include "GPA.h"
#include "GPAlist.h"
#include "UI.h"
#include <stdio.h>
#include <cstring>
#include <cstdio>
namespace sdds
{
    bool openFile(const char filename[]);
    void closeFile();
    bool readName(char name[]);
    bool readStno(int *stno);
    bool readGPA(double *gpa);
}
#endif