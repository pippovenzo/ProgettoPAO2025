#include "EditVisitor.h"
#include <QLabel> 

namespace view{
namespace edit{

EditVisitor::EditVisitor(media::storage::JsonStorage* repo){
    editWidget = new EditItem(repo);
}


void EditVisitor::visit(const media::Album &a){
    editWidget->renderForAlbum(a);
}

void EditVisitor::visit(const media::Article &a){
    editWidget->renderForArticle(a);
}
void EditVisitor::visit(const media::Book &b){
    editWidget->renderForBook(b);
}
void EditVisitor::visit(const media::Film &f){
    editWidget->renderForFilm(f);
}
void EditVisitor::visit(const media::Song &s){
    editWidget->renderForSong(s);
}

EditItem* EditVisitor::getEditWidget(){
    return editWidget;
}

}    
} 
