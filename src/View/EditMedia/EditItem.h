#ifndef EDIT_ITEM_H
#define EDIT_ITEM_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QTextEdit>
#include <QSpinBox>
#include <QFileDialog>
#include <QComboBox>

#include "../../Media/AbstractMedia.h"
#include "../../Media/Album.h"
#include "../../Media/Article.h"
#include "../../Media/Book.h"
#include "../../Media/Film.h"
#include "../../Media/Song.h"

#include "../../Media/Storage/JsonStorage.h"

namespace view{
namespace edit{

class EditItem: public QWidget{
    Q_OBJECT
    public:
        explicit EditItem(media::storage::JsonStorage* repo, QWidget* parent = 0);
        void renderForAlbum(const media::Album&);
        void renderForArticle(const media::Article&);
        void renderForBook(const media::Book&);
        void renderForFilm(const media::Film&);
        void renderForSong(const media::Song&);
        void renderForCreate(const std::string& type); 
    private:
        void renderForAbstractMedia(const media::AbstractMedia&);
        void renderImage(const std::string&);
        
        media::storage::JsonStorage* repo;

        QFormLayout* form;
        QVBoxLayout* vbox;
        QHBoxLayout* hbox;

        QLabel* image;
        QLineEdit* imagePath;
        QLineEdit* title;
        QLineEdit* author;
        QTextEdit* descr;
        QSpinBox* PblYear;
        
        QPushButton* applyBtn;
        QComboBox* type;
       

    public slots:
        void pickImage();
        void updateMedia(const media::AbstractMedia* media);
        void deleteItem(unsigned int id);
        void addSongToAlbum(const media::Album* a);
        void removeSongFromAlbum(const media::Album* a);
        void add(media::Album* a, const media::Song* s);
        void remove(media::Album* a, const media::Song* s);
    
    signals:
        void modifiedMedia();


};

}
}
#endif