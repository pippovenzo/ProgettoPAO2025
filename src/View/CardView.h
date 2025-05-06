#ifndef CARD_VIEW_H
#define CARD_VIEW_H

#include <QWidget>
#include <vector>

#include "../Media/Storage/JsonStorage.h"
#include "Layout/FlowLayout.h"


namespace view{

class CardView: public QWidget{
    Q_OBJECT
    private:   
        FlowLayout* flowLayout; 
        void purgeLayout();

        std::vector<std::string> chopString(std::string& string);
    
    public:
        CardView(media::storage::JsonStorage&);
        void renderCardView(media::storage::JsonStorage&);
        void renderStringMatching(media::storage::JsonStorage&, std::string& filter);

    signals:
        void editMedia(const media::AbstractMedia* media);
        void lookupMedia(const media::AbstractMedia* media);
};

}


#endif