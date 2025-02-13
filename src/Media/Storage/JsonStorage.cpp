#include <map>
#include <string>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>

#include "JsonStorage.h"
#include "JsonVisitor.h"
#include "../AbstractMedia.h"

namespace media{
namespace storage{

JsonStorage::JsonStorage(){}


QJsonObject JsonStorage::itemToJson(AbstractMedia& media){
    media.accept(storageVisitor);
    return storageVisitor.getObject();
}

JsonStorage& JsonStorage::create(AbstractMedia& item){
    storage.insert({item.getId(), &item});

    return *this;
}

std::vector<const AbstractMedia*> JsonStorage::extract() {
    std::vector<const AbstractMedia*> media;

    for(auto it = storage.begin(); it != storage.end(); ++it){
        media.push_back(it->second);
    }

    return media;
}

JsonStorage& JsonStorage::flushToFile() {
    std::vector<const AbstractMedia*> media = this->extract();
    QJsonArray jsonMedia;

    for(auto it = media.begin(); it != media.end(); ++it){

        jsonMedia.push_back(itemToJson(*(const_cast<AbstractMedia*>(*it))));
    }

    QJsonDocument doc(jsonMedia);
    QFile jsonFile("storage.json");
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(doc.toJson());

    return *this;
}

}
}