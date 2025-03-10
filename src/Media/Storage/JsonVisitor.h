#ifndef JSON_VISITOR_H
#define JSON_VISITOR_H

#include <QJsonObject>
#include "../Visitor.h"
#include "../Album.h"
#include "../Article.h"
#include "../Book.h"
#include "../Film.h"
#include "../Song.h"


namespace media{
namespace storage
{

class JsonVisitor: public ConstVisitor{
    private: 
        QJsonObject object;

    public:
        QJsonObject getObject() const;
        void visit(const Album &a);
        void visit(const Article &a);
        void visit(const Book &b);
        void visit(const Film &f);
        void visit(const Song &s);
};

} 
}
#endif