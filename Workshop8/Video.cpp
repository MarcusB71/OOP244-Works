#define _CRT_SECURE_NO_WARNINGS
#include "Video.h"
using namespace std;
namespace sdds {
    Video::Video(): m_length(0) {}
    Video::Video(int length) {
        length ? m_length = length : m_length = 0;
    }
    int Video::get()const {
        return m_length;
    }
    void Video::load(istream& istr) {
        istr >> m_length;
        istr.ignore(9999, ',');
    }
}