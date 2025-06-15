#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QStackedWidget>

#include "MediaCard.h"
#include "CardView.h"
#include "../Media/Storage/JsonStorage.h"

namespace view{

class MainWindow: public QMainWindow{
    Q_OBJECT
    private:
        CardView* cardView;
        QStackedWidget* stacked;
        media::storage::JsonStorage repo;
        QLineEdit* searchBar;
    public:
        MainWindow();
    
    public slots:
        void editMedia(const media::AbstractMedia*);
        void lookupMedia(const media::AbstractMedia*);
        void goPreviousPage();
        void updateCardView();
        void createNewMedia();
        void search(QLineEdit* query);
        void loadRepository();
        void createRepository();
        void returnHomeRepo();

};


}

#endif