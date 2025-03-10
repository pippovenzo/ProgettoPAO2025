#ifndef CONST_VISITOR_H
#define CONST_VISITOR_H

namespace media{

//incomplete classes declaration insted of includes cuase the creation of circular includes
class Album;
class Article;
class Book;
class Film;
class Song;

class ConstVisitor{
    public:
        virtual void visit(const Album &a) = 0;
        virtual void visit(const Article &a) = 0;
        virtual void visit(const Book &b) = 0;
        virtual void visit(const Film &f) = 0;
        virtual void visit(const Song &s) = 0;
};

}
#endif