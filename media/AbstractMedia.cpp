#include "AbstractMedia.h"
#include <sstream>
#include <iomanip>

namespace media{

AbstractMedia::AbstractMedia(const unsigned int Id, unsigned int PblDate, std::string Title, std::string Author, std::string Descr, 
                                        std::string PathToImage) : Id(Id), PblDate(PblDate), Title(Title), Author(Author), Descr(Descr), PathToImage(PathToImage) 
{

}

AbstractMedia::~AbstractMedia() {

}

unsigned int AbstractMedia::getId() const {
    return Id;
}

const std::string& AbstractMedia::getTitle() const{
    return Title;
}

AbstractMedia& AbstractMedia::setTitle(const std::string& _Title){
    Title = _Title;

    return *this;
}

const std::string& AbstractMedia::getAuthor() const {
    return Author;
}

AbstractMedia& AbstractMedia::setAuthor(const std::string& _Author){
    Author = _Author;

    return *this;
}

const unsigned int& AbstractMedia::getPblDate() const {
    return PblDate;
}

AbstractMedia& AbstractMedia::setPblDate(const unsigned int& _PblDate){
    PblDate = _PblDate;

    return *this;
}

const std::string& AbstractMedia::getDescr() const{
    return Descr;
}

AbstractMedia& AbstractMedia::setDescr(const std::string& _Descr){
    Descr = _Descr;

    return *this;
}

const std::string& AbstractMedia::getImagePath() const {
    return PathToImage;
}

AbstractMedia& AbstractMedia::setImagePath(const std::string& _ImagePath){
    PathToImage = _ImagePath;

    return *this;
}
    
}



