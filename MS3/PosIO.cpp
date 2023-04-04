#define _CRT_SECURE_NO_WARNINGS
#include "PosIO.h"
using namespace std;
namespace sdds {
    ostream& operator<<(ostream& ostr, const PosIO& io) {
        io.write(ostr);
        return ostr;
    }
    ofstream& operator<<(ofstream& ofstr, const PosIO& io) {
        io.save(ofstr);
        return ofstr;
    }
    istream& operator>>(istream& istr, PosIO& io) {
        io.read(istr);
        return istr;
    }
    ifstream& operator>>(ifstream& ifstr, PosIO& io) {
        io.load(ifstr);
        return ifstr;
    }

}