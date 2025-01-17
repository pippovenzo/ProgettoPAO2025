#include "Article.h"

namespace media{
    Article::Article(
            const unsigned int Id,
            unsigned int PblDate,
            std::string Title,
            std::string Author,
            std::string Descr,
            std::string PathToImage, 
            std::string magazine): TextualMedia(Id, PblDate, Title, Author, Descr, PathToImage), magazine(magazine) {}

    std::string Article::getMagazine() const{
        return magazine;
    }

    Article& Article::setMagazine(std::string& _magazine){
        magazine = _magazine;
        
        return *this;
    }
}