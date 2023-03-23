#ifndef SDDS_VIDEO_H_
#define SDDS_VIDEO_H_
#include "Media.h"
#include <iostream>
namespace sdds {
    class Video: public Media {
    private:
        int m_length;
    protected:
        int get()const;
    public:
        virtual ~Video() = default;
        Video();
        Video(int length);
        virtual void load(std::istream& istr);
        Video(const Video& vid) = delete;
        Video& operator=(const Video& vid) = delete;
    };
}
#endif