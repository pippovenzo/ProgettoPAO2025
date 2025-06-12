#include "MediaCard.h"
#include "MainWindow.h"

#include <QVBoxLayout>
#include <QPixmap>
#include <QDir>

namespace view{

MediaCard::MediaCard(const media::AbstractMedia* media, QWidget* parent): QWidget(parent), media(media){
    setFixedSize(210, 297);
    frame = new QFrame(this);
    frame->setStyleSheet(".QFrame{background-color: #aeaeae; border-radius: 10px;}");
    frame->setFixedSize(210, 297);

    
    QVBoxLayout* layout = new QVBoxLayout(frame);
    //layout->setSpacing(5);
    frame->setLayout(layout);
    
    //Setting immagine
    QString destPath = QString(PROJECT_DIR) + "/src/assets/images/";
    QPixmap imagePixMap(destPath + QString::fromStdString(media->getImagePath()));
    if(!imagePixMap) imagePixMap = QPixmap(":/src/assets/images/placeholder.png");
    
    image = new QLabel();
    image->setScaledContents(false); 
    image->setFixedSize(130, 190);
    image->setPixmap(imagePixMap.scaled(image->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    image->setAlignment(Qt::AlignHCenter);
    layout->addWidget(image, 0, Qt::AlignHCenter);

    //Setting titolo
    title = new QLabel();
    title->setText(QString::fromStdString(media->getTitle()));
    title->setStyleSheet("font-weight: bold;");
    title->setWordWrap(true);
    layout->addWidget(title);

    //Setting Autore
    author = new QLabel();
    author->setText(QString::fromStdString(media->getAuthor()));
    layout->addWidget(author);

    //Setting layout per pulsante
    QHBoxLayout* buttons = new QHBoxLayout();
    buttons->setSpacing(1);
    layout->addLayout(buttons);

    //Setting pulsante edit
    editButton = new QPushButton();
    editButton->setIcon(QIcon(QPixmap(":/src/assets/icons/edit.svg")));
    buttons->addWidget(editButton, 0, Qt::AlignCenter);

    //Setting pulsante view
    viewButton = new QPushButton();
    viewButton->setIcon(QIcon(QPixmap(":/src/assets/icons/view.svg")));
    buttons->addWidget(viewButton, 0, Qt::AlignCenter);
}

QPushButton* MediaCard::getEditButton() const{
    return editButton;
}

QPushButton* MediaCard::getLookupButton() const{
    return viewButton;
}

const media::AbstractMedia* MediaCard::getMedia() const{
    return media;
}
}
