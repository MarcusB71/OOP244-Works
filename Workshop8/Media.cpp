#define _CRT_SECURE_NO_WARNINGS
#include "Media.h"
using namespace std;
namespace sdds {
    ostream& operator<<(ostream& ostr, const Media& media) {
        return media.play(ostr);
    }
    istream& operator>>(istream& istr, Media& media) {
        media.load(istr);
        return istr;
    }
}