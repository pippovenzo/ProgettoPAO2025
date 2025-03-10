#include "CardView.h"
#include "../Media/AbstractMedia.h"
#include "MediaCard.h"



#include <vector>

#include <QScrollArea>

namespace view{

CardView::CardView(media::storage::JsonStorage& repo){
    flowLayout = new FlowLayout(this);
    renderCardView(repo);
}

void CardView::renderCardView(media::storage::JsonStorage& repo){ 
    purgeLayout();
    std::vector<const media::AbstractMedia*> media = repo.extract();
    MediaCard* tmp;

    for(auto it = media.begin(); it != media.end(); ++it){
        tmp = new MediaCard(*it);

        flowLayout->addWidget(tmp);
        connect(tmp->getEditButton(), &QPushButton::clicked, std::bind(&CardView::editMedia, this, tmp->getMedia()));
        connect(tmp->getLookupButton(), &QPushButton::clicked, std::bind(&CardView::lookupMedia, this, tmp->getMedia()));
    }
    
    setLayout(flowLayout);
}

void CardView::purgeLayout(){
    while (QLayoutItem* item = flowLayout->takeAt(0)){
        item->widget()->setParent(NULL);
        delete item;
    }
}

void CardView::renderStringMatching(media::storage::JsonStorage& repo, std::string& filter){
    purgeLayout();

    std::vector<const media::AbstractMedia*> media = repo.extract();
    MediaCard* tmp;
    std::string mediaString;

    for(auto it = media.begin(); it != media.end(); ++it){
        mediaString = (*it)->getTitle() + (*it)->getAuthor() + (*it)->getDescr() + std::to_string((*it)->getPblDate());

        std::transform(mediaString.begin(), mediaString.end(), mediaString.begin(),
                                    [](unsigned char c){ return std::tolower(c); });
        std::transform(filter.begin(), filter.end(), filter.begin(),
                                    [](unsigned char c){ return std::tolower(c); });


        if(mediaString.find(filter) != std::string::npos){
            tmp = new MediaCard(*it);
            flowLayout->addWidget(tmp);
            connect(tmp->getEditButton(), &QPushButton::clicked, std::bind(&CardView::editMedia, this, tmp->getMedia()));
            connect(tmp->getLookupButton(), &QPushButton::clicked, std::bind(&CardView::lookupMedia, this, tmp->getMedia()));
        }
    }
    
    setLayout(flowLayout);

}



}
