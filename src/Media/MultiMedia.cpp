#include "MultiMedia.h"

namespace media{

    MultiMedia::MultiMedia(const unsigned int Id,
                unsigned int PblDate,
                std::string Title,
                std::string Author,
                std::string Descr,
                std::string PathToImage, 
                unsigned int length): AbstractMedia(Id, PblDate, Title, Author, Descr, PathToImage), length(length){}

    unsigned int MultiMedia::getLength() const{
        return length;
    }

    MultiMedia& MultiMedia::setLength(unsigned int& seconds){
        length = seconds;

        return *this;
    }



}