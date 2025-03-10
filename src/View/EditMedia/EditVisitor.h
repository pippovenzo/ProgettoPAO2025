#ifndef EDIT_VISITOR_H
#define EDIT_VISITOR_H

#include <QWidget>

#include "../../Media/ConstVisitor.h"
#include "../../Media/Album.h"
#include "../../Media/Article.h"
#include "../../Media/Book.h"
#include "../../Media/Film.h"
#include "../../Media/Song.h"
#include "EditItem.h"
#include "../../Media/Storage/JsonStorage.h"

namespace view{
namespace edit{

class EditVisitor: public media::ConstVisitor{
    public:
        EditVisitor(media::storage::JsonStorage* repo);
        
        void visit(const media::Album &a);
        void visit(const media::Article &a);
        void visit(const media::Book &b);
        void visit(const media::Film &f);
        void visit(const media::Song &s);

        EditItem* getEditWidget();

    private:
        EditItem* editWidget;
};

}
}


#endif