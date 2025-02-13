#ifndef ARTICLE_H
#define ARTICLE_H

#include "TextualMedia.h"


namespace media{
class Article: public TextualMedia{
    private:
        std::string magazine;

    public:
        Article(
            const unsigned int Id,
            unsigned int PblDate,
            std::string Title,
            std::string Author,
            std::string Descr,
            std::string PathToImage, 
            std::string magazine
        );

        std::string getMagazine() const;
        Article& setMagazine(std::string& _magazine);
        void accept(Visitor&);
};
}
#endif