#ifndef ALBUM_H
#define ALBUM_H

#include "MultiMedia.h"
#include "Song.h"

#include <vector>

namespace media{

class Album: public MultiMedia{
    private:
        std::vector<const Song*> tracklist;
        void print() const;

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
        Album& remove(const Song& song);
        std::vector<const Song*> getTracklist() const;
        Album& setTracklist(std::vector<const Song*> newTracklist);
        void accept(Visitor&);
        void accept(ConstVisitor& v) const;
        

};

}

#endif