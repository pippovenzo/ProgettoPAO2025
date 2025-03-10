#include "LookupVisitor.h"

namespace view{
namespace lookup{

    LookupVisitor::LookupVisitor(media::storage::JsonStorage* repo){
        lookupWidget = new LookupWidget(repo);
    }

    void LookupVisitor::visit(const media::Album &a){
        lookupWidget->renderForAlbum(a);
    }

    void LookupVisitor::visit(const media::Article &a){
        lookupWidget->renderForArticle(a);
    }
    void LookupVisitor::visit(const media::Book &b){
        lookupWidget->renderForBook(b);
    }
    void LookupVisitor::visit(const media::Film &f){
        lookupWidget->renderForFilm(f);
    }
    void LookupVisitor::visit(const media::Song &s){
        lookupWidget->renderForSong(s);
    }
    
    LookupWidget* LookupVisitor::getLookupWidget(){
        return lookupWidget;
    }

}
}