#ifndef BOOK_H
#define BOOK_H

#include "TextualMedia.h"

namespace media{

class Book: public TextualMedia{
    private:
        unsigned int pages;
        std::string isbn;

    public:
        Book(const unsigned int Id,
            unsigned int PblDate,
            std::string Title,
            std::string Author,
            std::string Descr,
            std::string PathToImage,
            unsigned int pages, 
            std::string isbn);

        unsigned int getPages() const;
        Book& setPages(unsigned int& _pages);
        std::string getIsbn() const;
        Book& setIsbn(std::string& _isbn);
        void accept(Visitor&);


};   

}

#endif