#include "Book.h"

namespace media
{
    Book::Book(const unsigned int Id, unsigned int PblDate, std::string Title, std::string Author, std::string Descr,
                            std::string PathToImage, unsigned int pages, std::string isbn) 
               : TextualMedia(Id, PblDate, Title, Author, Descr, PathToImage), pages(pages), isbn(isbn) {}

    unsigned int Book::getPages() const{
        return pages;
    }

    Book& Book::setPages(unsigned int& _pages){
        pages = _pages;

        return *this;
    }

    std::string Book::getIsbn() const{
        return isbn;
    }

    Book& Book::setIsbn(std::string& _isbn){
        isbn = _isbn;

        return *this;
    }

    void Book::accept(Visitor& v){
        v.visit(*this);
    }
}