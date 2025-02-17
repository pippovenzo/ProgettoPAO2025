#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QWidget>

#include "MediaCard.h"
#include "CardView.h"
#include "../Media/Storage/JsonStorage.h"

namespace view{

class MainWindow: public QMainWindow{
    Q_OBJECT
    private:
        CardView* cardView;
        media::storage::JsonStorage repo;

    public:
        MainWindow();

};


}

#endif