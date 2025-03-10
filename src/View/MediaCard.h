#ifndef MEDIA_CARD_H
#define MEDIA_CARD_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QFrame>

#include "../Media/AbstractMedia.h"
#include "EditMedia/EditVisitor.h"

namespace view{

class MediaCard: public QWidget{
    Q_OBJECT
    private:
        QLabel* image;
        QLabel* title;
        QLabel* author;
        QPushButton *editButton;
        QPushButton* viewButton;
        QFrame* frame;
        const media::AbstractMedia* media;

    public:
        MediaCard(const media::AbstractMedia* media, QWidget* parent = 0);
        QPushButton* getEditButton() const;
        QPushButton* getLookupButton() const;
        const media::AbstractMedia* getMedia() const;
};
}

#endif