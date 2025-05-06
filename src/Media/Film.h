#ifndef FILM_H
#define FILM_H

#include "MultiMedia.h"


namespace media{

class Film: public MultiMedia{
    private:
        std::string country;

    public:
        Film(
            const unsigned int Id,
            unsigned int PblDate,
            std::string Title,
            std::string Author,
            std::string Descr,
            std::string PathToImage, 
            unsigned int length, 
            std::string country
        );

        std::string getCountry() const;
        Film& setCountry(std::string& _country);
        void accept(Visitor&);
        void accept(ConstVisitor& v) const;

};

}

#endif