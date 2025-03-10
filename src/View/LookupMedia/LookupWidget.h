#ifndef LOOKUP_WIDGET_H
#define LOOKUP_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QFormLayout>

#include "../../Media/AbstractMedia.h"
#include "../../Media/Album.h"
#include "../../Media/Article.h"
#include "../../Media/Book.h"
#include "../../Media/Film.h"
#include "../../Media/Song.h"

#include "../../Media/Storage/JsonStorage.h"

namespace view{
namespace lookup{

class LookupWidget: public QWidget{
    Q_OBJECT
    public:
        explicit LookupWidget(media::storage::JsonStorage* repo, QWidget* parent = 0);
        void renderForAlbum(const media::Album&);
        void renderForArticle(const media::Article&);
        void renderForBook(const media::Book&);
        void renderForFilm(const media::Film&);
        void renderForSong(const media::Song&);
    private:
        void renderForAbstractMedia(const media::AbstractMedia&);
        void renderImage(const std::string&);

        media::storage::JsonStorage* repo;

        QLabel* image;
        QFormLayout* form;
        QVBoxLayout* vbox;
        QHBoxLayout* hbox;

    
};

}
}

#endif