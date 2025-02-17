#include "MediaCard.h"

#include <QHBoxLayout>
#include <QPixmap>
#include <QPalette>

namespace view{

MediaCard::MediaCard(const media::AbstractMedia& media){
    frame = new QFrame(this);
    frame->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    QVBoxLayout* layout = new QVBoxLayout(frame);
    layout->setAlignment(Qt::AlignLeft);
    
    QPixmap imagePixMap(":/src/assets/images/" + QString::fromStdString(media.getImagePath()));
    if(!imagePixMap) imagePixMap = QPixmap(":/src/assets/images/placeholder.png");
    image = new QLabel();
    image->setPixmap(imagePixMap.scaledToWidth(100));
    layout->addWidget(image);

    title = new QLabel();
    title->setText(QString::fromStdString(media.getTitle()));
    layout->addWidget(title);

    editButton = new QPushButton(frame);
    editButton->setText("Edit");
    layout->addWidget(editButton);
    
}
}