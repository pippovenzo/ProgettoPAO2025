#include "CardView.h"
#include "../Media/AbstractMedia.h"
#include "MediaCard.h"


#include <vector>
#include <QHBoxLayout>

namespace view{

CardView::CardView(media::storage::JsonStorage& repo){
    renderCardView(repo);
}

void CardView::renderCardView(media::storage::JsonStorage& repo){
    repo.fetchFromFile();

    QHBoxLayout* hbox = new QHBoxLayout(this);
    //hbox->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    std::vector<const media::AbstractMedia*> media = repo.extract();

    for(auto it = media.begin(); it != media.end(); ++it){
        hbox->addWidget(new MediaCard(**it));
    }

}


}
