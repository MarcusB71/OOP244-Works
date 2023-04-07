/*I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
Name: Marcus Brown
email: mbrown106@myseneca.ca
id: 127900223
date: 2023/04/06
*/
#ifndef SDDS_VALIDATE_H
#define SDDS_VALIDATE_H
#include <iostream>
namespace sict {
    /// @brief validation of testValue[i] <= min 
    /// @tparam T no copy construct needed since const, >= overload needed
    /// @param min min reference for validation 
    /// @param testValue array of test values
    /// @param numEl num elements in testValue
    /// @param validResult bool array holds result for index of testValue
    /// @return true if all testValue are >= min, otherwise false
    template <typename T>
    bool validate(const T& min, const T* testValue, int numEl, bool* validResult) {
        bool valid = true;
        for (int i = 0; i < numEl; i++)
        {
            if (testValue[i] >= min)
            {
                validResult[i] = true;
            }
            else {
                validResult[i] = false;
                valid = false;
            }
        }
        return valid;
    }
}
#endif