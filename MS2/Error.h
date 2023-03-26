#ifndef SDDS_ERROR_H_
#define SDDS_ERROR_H_
#include <iostream>
namespace sdds {
    class Error
    {
    private:
        char* m_errDesc; //if null there is no error
    public:
        Error();
        Error(const char* errMsg);
        Error(const Error& error); //const might cause problems?
        Error& operator=(const Error& error); //const might cause problems?
        Error& operator=(const char* errorMsg); //const might cause problems?
        operator bool()const;
        Error& clear();
        const char* getError()const;
        ~Error();
    };
    std::ostream& operator<<(std::ostream& ostr, const Error& error);
}
#endif