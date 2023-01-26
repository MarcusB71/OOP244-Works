#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include "File.h"
using namespace std;
namespace sdds
{
   FILE *fptr;
   // opens the data file and returns true if successful
   bool openFile(const char filename[])
   {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }

   // closes the data file
   void closeFile()
   {
      if (fptr)
         fclose(fptr);
   }

   // reads the name of the GPA struct from the global fptr File pointer
   // returns true if successful
   bool readName(char name[])
   {
      return fscanf(fptr, "%116[^,],", name) == 1;
   }

   // reads the student num of the GPA struct from the global fptr File pointer
   // returns true if successful
   bool readStno(int *stno)
   {
      return fscanf(fptr, "%d,", stno) == 1;
   }

   // reads the gpa of the GPA struct from the global fptr File pointer
   // returns true if successful
   bool readGPA(double *gpa)
   {
      return fscanf(fptr, "%lf\n", gpa) == 1;
   }
}