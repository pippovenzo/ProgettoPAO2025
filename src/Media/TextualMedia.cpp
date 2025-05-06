#include "TextualMedia.h"

namespace media{

    TextualMedia::TextualMedia(const unsigned int Id, unsigned int PblDate, std::string Title, std::string Author, 
            std::string Descr, std::string PathToImage): AbstractMedia(Id, PblDate, Title, Author, Descr, PathToImage){}

    

} // namespace item
