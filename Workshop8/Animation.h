#ifndef SDDS_ANIMATION_H_
#define SDDS_ANIMATION_H_
#include "Video.h"
#include <iostream>
namespace sdds {
    class Animation: public Video {
    private:
        int m_dimmension;
    public:
        Animation();
        Animation(int length, int dimension);
        void load(std::istream& istr);
        std::ostream& play(std::ostream& ostr)const;
    };
}
#endif