#include "Film.h"

namespace media{
    Film::Film(
        const unsigned int Id,
        unsigned int PblDate,
        std::string Title,
        std::string Author,
        std::string Descr,
        std::string PathToImage, 
        unsigned int length, 
        std::string country
    ): MultiMedia(Id, PblDate, Title, Author, Descr, PathToImage, length), country(country) {}

    Film::~Film(){}

    std::string Film::getCountry() const{
        return country;
    }

    Film& Film::setCountry(std::string& _country){
        country = _country;

        return *this;
    }

    void Film::accept(Visitor& v){
        v.visit(*this);
    }

    void Film::accept(ConstVisitor& v) const{
        v.visit(*this);
    }
}