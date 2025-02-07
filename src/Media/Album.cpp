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

    Album& Album::remove(unsigned int pos){
        tracklist.erase(tracklist.begin() + pos);

        return *this;
    }

    void Album::print(){
        for(auto it = tracklist.begin(); it != tracklist.end(); ++it){
            std::cout << (*it)->getTitle() << std::endl;
        }
    }
    
}