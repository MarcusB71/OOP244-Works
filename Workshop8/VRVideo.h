#ifndef SDDS_VRVIDEO_H_
#define SDDS_VRVIDEO_H_
#include "Video.h"
#include <iostream>
namespace sdds {
    class VRVideo: public Video {
    private:
        char* m_equipment;
    public:
        VRVideo();
        VRVideo(int length, const char* name);
        ~VRVideo();
        void load(std::istream& istr);
        std::ostream& play(std::ostream& ostr)const;

    };
}
#endif