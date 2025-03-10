#ifndef LOOKUP_VISITOR_H
#define LOOKUP_VISITOR_H

#include <QWidget>

#include "../../Media/ConstVisitor.h"
#include "../../Media/Album.h"
#include "../../Media/Article.h"
#include "../../Media/Book.h"
#include "../../Media/Film.h"
#include "../../Media/Song.h"
#include "../../Media/Storage/JsonStorage.h"
#include "LookupWidget.h"

namespace view{
namespace lookup{

class LookupVisitor: public media::ConstVisitor{
    public:
        LookupVisitor(media::storage::JsonStorage* repo);
        
        void visit(const media::Album &a);
        void visit(const media::Article &a);
        void visit(const media::Book &b);
        void visit(const media::Film &f);
        void visit(const media::Song &s);

        LookupWidget* getLookupWidget();

    private:
        LookupWidget* lookupWidget;


};

}
}

#endif