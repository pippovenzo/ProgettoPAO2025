#ifndef MEDIA_CARD_H
#define MEDIA_CARD_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QFrame>

#include "../Media/AbstractMedia.h"

namespace view{

class MediaCard: public QWidget{
    Q_OBJECT
    private:
        QLabel* image;
        QLabel* title;
        QPushButton *editButton;
        QFrame* frame;

    public:
        MediaCard(const media::AbstractMedia& media);

};
}

#endif