#include "Song.h"

namespace media{

    Song::Song(
        const unsigned int Id,
        unsigned int PblDate,
        std::string Title,
        std::string Author,
        std::string Descr,
        std::string PathToImage, 
        unsigned int length, 
        std::string genre): MultiMedia(Id, PblDate, Title, Author, Descr, PathToImage, length), genre(genre){}

    std::string Song::getGenre() const{
        return genre;
    }

    Song& Song::setGenre(std::string& _genre){
        genre = _genre;

        return *this;
    }

    void Song::accept(Visitor& v){
        v.visit(*this);
    }

}