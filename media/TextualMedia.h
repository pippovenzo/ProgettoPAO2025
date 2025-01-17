#ifndef TEXTUAL_MEDIA_H
#define TEXTUAL_MEDIA_H

#include "AbstractMedia.h"

namespace media{

class TextualMedia: public AbstractMedia{
    public:
        TextualMedia(
            const unsigned int Id,
            unsigned int PblDate,
            std::string Title,
            std::string Author,
            std::string Descr,
            std::string PathToImage
        );

        virtual ~TextualMedia() = 0;
};

}



#endif