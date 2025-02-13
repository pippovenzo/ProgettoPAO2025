#ifndef ALBUM_H
#define ALBUM_H

#include "MultiMedia.h"
#include "Song.h"

#include <vector>

namespace media{

class Album: public MultiMedia{
    private:
        std::vector<const Song*> tracklist;

    public:
        Album(
            const unsigned int Id,
            unsigned int PblDate,
            std::string Title,
            std::string Author,
            std::string Descr,
            std::string PathToImage);

        ~Album(){}
        
        Album& add(const Song& song);
        Album& remove(unsigned int pos);
        static unsigned int length(Album& album);
        std::vector<const Song*> getTracklist() const;
        void accept(Visitor&);
        void print();


};

}

#endif