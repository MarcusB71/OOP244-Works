#define _CRT_SECURE_NO_WARNINGS
#include "VRVideo.h"
#include <cstring>
using namespace std;
namespace sdds {
    VRVideo::VRVideo():Video(), m_equipment(nullptr) {}

    VRVideo::VRVideo(int length, const char* name):Video(length) {
        if (name != nullptr && length > 0)
        {
            delete[] m_equipment;
            m_equipment = new char[length + 1];
            strcpy(m_equipment, name);
        }
        else {
            m_equipment = nullptr;
        }
    }
    VRVideo::~VRVideo() {
        if (m_equipment != nullptr)
        {
            delete[] m_equipment;
        }
    }
    void VRVideo::load(istream& istr) {
        Video::load(istr);
        delete[] m_equipment;
        char name[50];
        istr.get(name, 50, '\n');
        m_equipment = new char[strlen(name) + 1];
        strcpy(m_equipment, name);
    }
    ostream& VRVideo::play(ostream& ostr)const {
        if (m_equipment != nullptr)
        {
            ostr << "VRVideo requires " << m_equipment << endl;
            ostr << "Video Length = " << get();
        }
        return ostr;
    }
}