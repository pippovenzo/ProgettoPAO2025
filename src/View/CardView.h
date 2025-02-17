#ifndef CARD_VIEW_H
#define CARD_VIEW_H

#include <QWidget>
#include <vector>

#include "../Media/Storage/JsonStorage.h"


namespace view{

class CardView: public QWidget{
    Q_OBJECT
    
    public:
        CardView(media::storage::JsonStorage&);
    
    private:
        void renderCardView(media::storage::JsonStorage&);
};

}


#endif