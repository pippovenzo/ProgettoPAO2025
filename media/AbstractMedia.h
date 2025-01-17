#ifndef ABSTRACT_MEDIA_H
#define ABSTRACT_MEDIA_H

#include <string>

namespace media{

class AbstractMedia {
    private:
        const unsigned int Id;
        unsigned int PblDate; //Anno di pubblicazione
        std::string Title;
        std::string Author;
        std::string Descr;
        std::string PathToImage;

    protected:
        AbstractMedia(
            const unsigned int Id,
            unsigned int PblDate,
            std::string Title,
            std::string Author,
            std::string Descr,
            std::string PathToImage
        );
    
    public:
        virtual ~AbstractMedia() = 0;
        unsigned int getId() const;
        const unsigned int& getPblDate() const;
        AbstractMedia& setPblDate(const unsigned int& _PblDate);
        const std::string& getTitle() const;
        AbstractMedia& setTitle(const std::string& _Title);
        const std::string& getAuthor() const;
        AbstractMedia& setAuthor(const std::string& _Author);
        const std::string& getDescr() const;
        AbstractMedia& setDescr(const std::string& _Descr);
        const std::string& getImagePath() const;
        AbstractMedia& setImagePath(const std::string& _ImagePath);
};

}

#endif