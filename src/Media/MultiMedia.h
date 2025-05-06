#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include "AbstractMedia.h"

namespace media{

class MultiMedia: public AbstractMedia{
    private:
        unsigned int length;

    public:
        MultiMedia(
            const unsigned int Id,
            unsigned int PblDate,
            std::string Title,
            std::string Author,
            std::string Descr,
            std::string PathToImage, 
            unsigned int length
        );

        unsigned int getLength() const;
        MultiMedia& setLength(unsigned int& _length);
};

}

#endif