#define _CRT_SECURE_NO_WARNINGS
#include "Animation.h"
#include <cstring>
using namespace std;
namespace sdds {
    Animation::Animation(): m_dimmension(0) {}
    Animation::Animation(int length, int dimension):Video(length) {
        m_dimmension = (dimension == 2 || dimension == 3) ? dimension : 0;
    }

    void Animation::load(istream& istr) {
        Video::load(istr);
        istr >> m_dimmension; //if value still in buffer not sure if this will read into variable
    }
    ostream& Animation::play(ostream& ostr)const {
        if (m_dimmension == 3 || m_dimmension == 4)
        {
            ostr << "Animation is in " << m_dimmension << "-D" << endl;
            ostr << "Video Length = " << get();
        }
        return ostr;
    }
}