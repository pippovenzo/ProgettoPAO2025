#ifndef VISITOR_H
#define VISITOR_H

namespace media{

//incomplete classes declaration insted of includes cuase the creation of circular includes
class Album;
class Article;
class Book;
class Film;
class Song;

class Visitor{
    public:
        virtual void visit(Album &a) = 0;
        virtual void visit(Article &a) = 0;
        virtual void visit(Book &b) = 0;
        virtual void visit(Film &f) = 0;
        virtual void visit(Song &s) = 0;
};

}
#endif