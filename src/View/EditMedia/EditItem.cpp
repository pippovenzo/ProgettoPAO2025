#include "EditItem.h"
#include "../MainWindow.h"

#include <QPushButton>
#include <QDialog>
#include <QCheckBox>
#include <QFileDialog>
#include <QMessageBox>


namespace view{
namespace edit{


EditItem::EditItem(media::storage::JsonStorage* repo, bool createMode, QWidget* parent): 
                                            QWidget(parent), repo(repo), createMode(createMode){
    hbox = new QHBoxLayout(this);
    vbox = new QVBoxLayout();

    //Image settings
    image = new QLabel();
    image->setScaledContents(false); 
    image->setFixedSize(200, 260);
    image->setAlignment(Qt::AlignRight);

    hbox->addWidget(image, 0, Qt::AlignHCenter);
    hbox->addLayout(vbox);

    form = new QFormLayout();
    vbox->addLayout(form);

    
}

void EditItem::renderForCreate(const std::string& type){
    unsigned int maxKey = repo->getMaxKey();

    if(type == "Album"){
        renderForAlbum(*(new media::Album(maxKey+1, 0, "", "", "", "")));
    }
    else if(type == "Article"){
        renderForArticle(*(new media::Article(maxKey+1, 0, "", "", "", "", "")));
    }
    else if(type == "Book"){
        renderForBook(*(new media::Book(maxKey+1, 0, "", "", "", "", 0, "")));
    }
    else if(type == "Film"){
        renderForFilm(*(new media::Film(maxKey+1, 0, "", "", "", "", 0, "")));
    }
    else if(type == "Song"){
        renderForSong(*(new media::Song(maxKey+1, 0, "", "", "", "", 0, "")));
    }
}

void EditItem::renderImage(const std::string& imagePathStr){
    QPixmap imagePixMap(QString::fromStdString(imagePathStr));
    if(!imagePixMap) imagePixMap = QPixmap(":/src/assets/images/placeholder.png");

    image->setPixmap(imagePixMap.scaled(image->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
   
}
void EditItem::renderForAbstractMedia(const media::AbstractMedia& media){
    renderImage(media.getImagePath());
   
    title = new QLineEdit(QString::fromStdString(media.getTitle()));
    form->addRow("Titolo", title);

    author = new QLineEdit(QString::fromStdString(media.getAuthor()));
    form->addRow("Autore", author);

    descr = new QTextEdit(QString::fromStdString(media.getDescr()));
    descr->setMaximumHeight(100);
    form->addRow("Descrizione", descr);

    PblYear = new QSpinBox();
    PblYear->setMaximum(3000);
    PblYear->setValue(media.getPblDate());
    form->addRow("Anno pubblicazione", PblYear);

    QHBoxLayout* imageHbox = new QHBoxLayout();
    imagePath = new QLineEdit(QString::fromStdString(media.getImagePath()));
    imageHbox->addWidget(imagePath);
    QPushButton* selectImage = new QPushButton("Select");

    imageHbox->addWidget(selectImage);
    form->addRow("Image", imageHbox);

    if(!createMode){
        QPushButton* deleteButton = new QPushButton("Delete media");
        vbox->addWidget(deleteButton);

        connect(deleteButton, &QPushButton::clicked, this, std::bind(&EditItem::deleteItem, this, media.getId()));
    }

    applyBtn = new QPushButton("Apply");
    vbox->addWidget(applyBtn);

    connect(selectImage, &QPushButton::clicked, this, &EditItem::pickImage);
   
    
}

void EditItem::renderForAlbum(const media::Album& a){
    renderForAbstractMedia(a);
    
    std::vector<const media::Song*> trackV = a.getTracklist();
    QTextEdit* tracklist = new QTextEdit();
    tracklist->setReadOnly(true);
    tracklist->setMaximumHeight(100);

    for(auto it = trackV.begin(); it != trackV.end(); ++it){
        tracklist->append(QString::fromStdString((*it)->getTitle()));
    }   
    
    QHBoxLayout* tracklistMgt = new QHBoxLayout();
    QPushButton* addSong = new QPushButton("Add song");
    QPushButton* removeSong = new QPushButton("Remove song");

    connect(addSong, &QPushButton::clicked, this, std::bind(&EditItem::addSongToAlbum, this, &a));
    connect(removeSong, &QPushButton::clicked, this, std::bind(&EditItem::removeSongFromAlbum, this, &a));

    tracklistMgt->addWidget(addSong);
    tracklistMgt->addWidget(removeSong);
    form->addRow("Tracklist", tracklist);
    form->addRow("", tracklistMgt);

    connect(applyBtn, &QPushButton::clicked, this, std::bind(&EditItem::updateMedia, this, &a));
} 

void EditItem::renderForArticle(const media::Article& a){
    renderForAbstractMedia(a);
    
    QLineEdit* magazineName = new QLineEdit(QString::fromStdString(a.getMagazine()));
    magazineName->setObjectName("magazineName");
    form->addRow("Magazine: ", magazineName);

    connect(applyBtn, &QPushButton::clicked, this, std::bind(&EditItem::updateMedia, this, &a));
} 

void EditItem::renderForBook(const media::Book& b){
    renderForAbstractMedia(b);
    
    QSpinBox* pagesField = new QSpinBox();
    pagesField->setObjectName("pagesField");
    pagesField->setMaximum(100000);
    pagesField->setValue(b.getPages());
    form->addRow("Numero di pagine", pagesField);

    QLineEdit* isbnField = new QLineEdit(QString::fromStdString(b.getIsbn()));
    isbnField->setObjectName("isbnField");
    form->addRow("ISBN", isbnField);

    connect(applyBtn, &QPushButton::clicked, this, std::bind(&EditItem::updateMedia, this, &b));
} 

void EditItem::renderForFilm(const media::Film& f){
    renderForAbstractMedia(f);
    
    QSpinBox* lengthField = new QSpinBox(); 
    lengthField->setObjectName("lengthField");
    lengthField->setMaximum(100000);
    lengthField->setValue(f.getLength());
    lengthField->setSuffix("m");
    form->addRow("Durata", lengthField);

    QLineEdit* countryField = new QLineEdit(QString::fromStdString(f.getCountry()));
    countryField->setObjectName("countryField");
    form->addRow("Paese", countryField);

    connect(applyBtn, &QPushButton::clicked, this, std::bind(&EditItem::updateMedia, this, &f));
}

void EditItem::renderForSong(const media::Song& s){
    renderForAbstractMedia(s);
    
    QSpinBox* lengthField = new QSpinBox(); 
    lengthField->setObjectName("lengthField");
    lengthField->setMaximum(100000);
    lengthField->setValue(s.getLength());
    lengthField->setSuffix("s");
    form->addRow("Durata", lengthField);

    QLineEdit* genreField = new QLineEdit(QString::fromStdString(s.getGenre()));
    genreField->setObjectName("genreField");
    form->addRow("Genre", genreField);

    connect(applyBtn, &QPushButton::clicked, this, std::bind(&EditItem::updateMedia, this, &s));
} 

void EditItem::pickImage(){
    imagePath->setText(QFileDialog::getOpenFileName(this, "Select an image", "./", "Image Files (*.png *.jpg *.bmp)"));
}

void EditItem::updateMedia(const media::AbstractMedia* media){
    std::string newTitle = title->text().toStdString();
    std::string newAuthor = author->text().toStdString();
    std::string newDescr = descr->toPlainText().toStdString();
    unsigned int newPblDate = PblYear->value();
    std::string newImage = imagePath->text().toStdString();

    if(auto ptr = dynamic_cast<const media::Album*>(media)){
        media::Album* newAlbum = new media::Album(media->getId(), newPblDate, newTitle, newAuthor, newDescr, newImage);
        newAlbum->setTracklist(ptr->getTracklist());
        repo->update(*(newAlbum));
    }
    else if(dynamic_cast<const media::Article*>(media) != nullptr){
        std::string newMagazine = findChild<QLineEdit*>("magazineName")->text().toStdString();

        repo->update(*(new media::Article(media->getId(), newPblDate, newTitle, newAuthor, newDescr, newImage, newMagazine)));
    }
    else if(dynamic_cast<const media::Book*>(media) != nullptr){
        unsigned int newPages = findChild<QSpinBox*>("pagesField")->value();
        std::string newIsbn = findChild<QLineEdit*>("isbnField")->text().toStdString();

        repo->update(*(new media::Book(media->getId(), newPblDate, newTitle, newAuthor, newDescr, newImage, newPages, newIsbn)));
    }
    else if(dynamic_cast<const media::Film*>(media) != nullptr){
        unsigned int newLength = findChild<QSpinBox*>("lengthField")->value();
        std::string newCountry = findChild<QLineEdit*>("countryField")->text().toStdString();

        repo->update(*(new media::Film(media->getId(), newPblDate, newTitle, newAuthor, newDescr, newImage, newLength, newCountry)));
    }
    else if(dynamic_cast<const media::Song*>(media) != nullptr){
        unsigned int newLength = findChild<QSpinBox*>("lengthField")->value();
        std::string newGenre = findChild<QLineEdit*>("genreField")->text().toStdString();
        
        repo->update(*(new media::Song(media->getId(), newPblDate, newTitle, newAuthor, newDescr, newImage, newLength, newGenre)));
    }

    if(newImage != media->getImagePath()) renderImage(newImage); 

    repo->flushToFile();

    emit modifiedMedia();
}

void EditItem::deleteItem(unsigned int id){

    if (QMessageBox::Yes == QMessageBox::question(this, "", "Sei sicuro di voler cancellare il media?", QMessageBox::Yes | QMessageBox::No)){
        repo->remove(id);
        repo->flushToFile();

        emit modifiedMedia();
    }
    
}

void EditItem::addSongToAlbum(const media::Album* a){
    QDialog* dialog = new QDialog;
    dialog->setModal(true);

    QVBoxLayout* vbox = new QVBoxLayout(dialog);
    QLabel* title = new QLabel(QString::fromStdString(a->getTitle()));
    title->setStyleSheet("font-weight: bold;");

    vbox->addWidget(title);

    QFormLayout* form = new QFormLayout();
    vbox->addLayout(form);

    std::vector<const media::AbstractMedia*> media = repo->extract();
    media::Album* nc_a = const_cast<media::Album*>(a);
   
    const media::Song* newSong;

    QPushButton* tmpButton;
    for(auto it = media.begin(); it != media.end(); ++it){
        if((newSong =dynamic_cast<const media::Song*>(*it))){
            if((*it)->getAuthor() == a->getAuthor()){

                tmpButton = new QPushButton("Add");
                form->addRow(QString::fromStdString((*it)->getTitle()), tmpButton);

                connect(tmpButton, &QPushButton::clicked, this, std::bind(&EditItem::add, this, nc_a, newSong));

            }          
        }
    }
    
    dialog->show();
}

void EditItem::removeSongFromAlbum(const media::Album* a){
    QDialog* dialog = new QDialog;
    dialog->setModal(true);

    QVBoxLayout* vbox = new QVBoxLayout(dialog);
    QLabel* title = new QLabel(QString::fromStdString(a->getTitle()));
    title->setStyleSheet("font-weight: bold;");

    vbox->addWidget(title);

    QFormLayout* form = new QFormLayout();
    vbox->addLayout(form);

    media::Album* nc_a = const_cast<media::Album*>(a);
    std::vector<const media::Song*> tracklist = a->getTracklist();

    QPushButton* tmpButton;
    for(auto it = tracklist.begin(); it != tracklist.end(); ++it){
        tmpButton = new QPushButton("Remove");
        form->addRow(QString::fromStdString((*it)->getTitle()), tmpButton);

        connect(tmpButton, &QPushButton::clicked, this, std::bind(&EditItem::remove, this, nc_a, *it));
    }
    
    dialog->show();
}

void EditItem::add(media::Album* a, const media::Song* s){
    a->add(*s);
}

void EditItem::remove(media::Album* a, const media::Song* s){
    a->remove(*s);
}

}
}