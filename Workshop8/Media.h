#ifndef SDDS_MEDIA_H_
#define SDDS_MEDIA_H_
#include <iostream>
namespace sdds {
    class Media
    {
    private:

    public:
        virtual ~Media() = default;
        virtual std::ostream& play(std::ostream& ostr = std::cout)const = 0;//might not need const
        virtual void load(std::istream& istr) = 0;
    };
    std::ostream& operator<<(std::ostream& ostr, const Media& media); // const might give problems
    std::istream& operator>>(std::istream& istr, Media& media);

}
#endif