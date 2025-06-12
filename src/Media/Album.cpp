#include "Album.h"
#include <algorithm>
#include <iostream>

namespace media{
    Album::Album( 
        const unsigned int Id,
        unsigned int PblDate,
        std::string Title,
        std::string Author,
        std::string Descr,
        std::string PathToImage): MultiMedia(Id, PblDate, Title, Author, Descr, PathToImage, 0) {}

    Album& Album::add(const Song& song){
        if(song.getAuthor() == getAuthor() && std::find(tracklist.begin(), tracklist.end(), &song) == tracklist.end())
            tracklist.push_back(&song); 

        return *this;
    }

    Album& Album::remove(const Song& song){
        auto pos = std::find(tracklist.begin(), tracklist.end(), &song);
        if(pos != tracklist.end()) tracklist.erase(pos);

        return *this;
    }

    std::vector<const Song*> Album::getTracklist() const{
        return tracklist;
    }
    Album& Album::setTracklist(std::vector<const Song*> newTracklist){
        tracklist = newTracklist;

        return *this;
    }

    void Album::accept(Visitor& v){
        v.visit(*this);
    }

    void Album::accept(ConstVisitor& v) const{
        v.visit(*this);
    }
    
}