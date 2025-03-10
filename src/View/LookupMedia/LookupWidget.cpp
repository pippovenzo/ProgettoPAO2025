#include "LookupWidget.h"

#include <QTextEdit>


namespace view{
namespace lookup{


LookupWidget::LookupWidget(media::storage::JsonStorage* repo, QWidget* parent): QWidget(parent), repo(repo){
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

void LookupWidget::renderForAbstractMedia(const media::AbstractMedia& media){
    renderImage(media.getImagePath());
   
    QLabel* title = new QLabel(QString::fromStdString(media.getTitle()));
    title->setStyleSheet("font-weight: bold;");
    form->addRow("Titolo", title);

    QLabel* author = new QLabel(QString::fromStdString(media.getAuthor()));
    author->setStyleSheet("font-weight: bold;");
    form->addRow("Autore", author);

    QTextEdit* descr = new QTextEdit(QString::fromStdString(media.getDescr()));
    descr->setReadOnly(true);
    descr->setMaximumHeight(100);
    descr->setStyleSheet("font-weight: bold;");
    form->addRow("Descrizione", descr);

    QLabel* PblYear = new QLabel(QString::number(media.getPblDate()));
    PblYear->setStyleSheet("font-weight: bold;");
    form->addRow("Anno pubblicazione", PblYear); //FARE VISITOR PER LOOKUP
}
void LookupWidget::renderForAlbum(const media::Album& a){
    renderForAbstractMedia(a);

    std::vector<const media::Song*> trackV = a.getTracklist();
    QTextEdit* tracklist = new QTextEdit();
    tracklist->setReadOnly(true);
    tracklist->setMaximumHeight(100);
    tracklist->setStyleSheet("font-weight: bold;");

    float length = 0;

    for(auto it = trackV.begin(); it != trackV.end(); ++it){
        tracklist->append(QString::fromStdString((*it)->getTitle()));
        length += (*it)->getLength();
    } 

    length = length/60;
    QLabel* lengthLabel = new QLabel(QString::number((int)length) + " minuti");

    form->addRow("Tracklist", tracklist);
    form->addRow("Durata", lengthLabel);

    
}
void LookupWidget::renderForArticle(const media::Article& a){
    renderForAbstractMedia(a);
    
    QLabel* magazineName = new QLabel(QString::fromStdString(a.getMagazine()));
    form->addRow("Magazine: ", magazineName);
}
void LookupWidget::renderForBook(const media::Book& b){
    renderForAbstractMedia(b);
    
    QLabel* pagesField = new QLabel(QString::number(b.getPages()));
    pagesField->setStyleSheet("font-weight: bold;");
    form->addRow("Numero di pagine", pagesField);

    QLabel* isbnField = new QLabel(QString::fromStdString(b.getIsbn()));
    isbnField->setStyleSheet("font-weight: bold;");
    form->addRow("ISBN", isbnField);
}
void LookupWidget::renderForFilm(const media::Film& f){
    renderForAbstractMedia(f);
    
    QLabel* lengthField = new QLabel(QString::number(f.getLength()));
    lengthField->setStyleSheet("font-weight: bold;");
    form->addRow("Durata", lengthField);

    QLabel* countryField = new QLabel(QString::fromStdString(f.getCountry()));
    countryField->setStyleSheet("font-weight: bold;");
    form->addRow("Paese", countryField);
}
void LookupWidget::renderForSong(const media::Song& s){
    renderForAbstractMedia(s);

    int lengthM = s.getLength() / 60;
    int lengthS = s.getLength() - lengthM*60;
     
    QLabel* lengthField = new QLabel(QString::number(lengthM) + ":" + QString::number(lengthS) + " minuti");
    lengthField->setStyleSheet("font-weight: bold;");
    form->addRow("Durata", lengthField);

    QLabel* genreField = new QLabel(QString::fromStdString(s.getGenre()));
    genreField->setStyleSheet("font-weight: bold;");
    form->addRow("Genere", genreField);
}

void LookupWidget::renderImage(const std::string& imagePathStr){
    QPixmap imagePixMap(QString::fromStdString(imagePathStr));
    if(!imagePixMap) imagePixMap = QPixmap(":/src/assets/images/placeholder.png");

    image->setPixmap(imagePixMap.scaled(image->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
   
}

}
}