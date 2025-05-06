#ifndef SONG_H
#define SONG_H

#include "MultiMedia.h"


namespace media{

class Song: public MultiMedia{
    private:
        std::string genre;

    public: 
        Song(const unsigned int Id,
            unsigned int PblDate,
            std::string Title,
            std::string Author,
            std::string Descr,
            std::string PathToImage, 
            unsigned int length, 
            std::string genre);
        
        std::string getGenre() const;
        Song& setGenre(std::string& _genre);
        void accept(Visitor&);
        void accept(ConstVisitor& v) const;
};

} 


#endif