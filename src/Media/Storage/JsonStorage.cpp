#include <map>
#include <string>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QDir>
#include <iostream>

#include "JsonStorage.h"
#include "JsonVisitor.h"
#include "../AbstractMedia.h"

namespace media{
namespace storage{

    
JsonStorage::JsonStorage(std::string filePath): filePath(filePath){
}


QJsonObject JsonStorage::itemToJson(const AbstractMedia& media){
    media.accept(storageVisitor);
    return storageVisitor.getObject();
}

JsonStorage& JsonStorage::create(AbstractMedia& item){
    repository[item.getId()] = &item;

    return *this;
}

JsonStorage& JsonStorage::update(AbstractMedia& item){
    if(repository.count(item.getId()) > 0){
        delete repository[item.getId()];
    }

    create(item);
    return *this;
}

const AbstractMedia* JsonStorage::read(unsigned int id) const{
    if(repository.count(id) > 0) return repository.at(id);

    return nullptr;
}

JsonStorage& JsonStorage::remove(const unsigned int id){
    if(repository.count(id) > 0){
        delete repository[id];
        repository.erase(id);
    }
    return *this;
}

std::vector<const AbstractMedia*> JsonStorage::extract() const{
    std::vector<const AbstractMedia*> media;

    for(auto it = repository.begin(); it != repository.end(); ++it){
        media.push_back(it->second);
    }

    return media;
}

JsonStorage& JsonStorage::flushToFile(){
    std::vector<const AbstractMedia*> media = this->extract();
    QJsonArray jsonMedia;

    for(auto it = media.begin(); it != media.end(); ++it){
        jsonMedia.push_back(itemToJson(**it));
    }

    QJsonDocument doc(jsonMedia);
    QFile jsonFile(QString::fromStdString(filePath));
    jsonFile.open(QFile::WriteOnly | QIODevice::Text);
    jsonFile.write(doc.toJson());
    jsonFile.close();

    return *this;
}

JsonStorage& JsonStorage::fetchFromFile(){
    repository.erase(repository.begin(), repository.end());

    QFile jsonFile(QString::fromStdString(filePath));
    jsonFile.open(QIODevice::ReadOnly | QIODevice::Text);

    QJsonDocument doc = QJsonDocument::fromJson(jsonFile.readAll());
    jsonFile.close();

    QJsonArray jsonMedia = doc.array();
    QJsonObject object;
    
    if(!jsonMedia.isEmpty()){
        for(auto it = jsonMedia.begin(); it != jsonMedia.end(); ++it){
            object = (*it).toObject();
            unsigned int id = object.value("id").toInt();

            if(repository.count(id) == 0) repository[id] = JsonToItem(object);
        }
    }

    return *this;
}

const AbstractMedia* JsonStorage::fetchObject(unsigned int id){
    QFile jsonFile(QString::fromStdString(filePath));
    jsonFile.open(QIODevice::ReadOnly | QIODevice::Text);
    
    QJsonDocument doc = QJsonDocument::fromJson(jsonFile.readAll());
    jsonFile.close();

    QJsonArray jsonMedia = doc.array();
    QJsonObject object;

    if(!jsonMedia.isEmpty()){
        for(auto it = jsonMedia.begin(); it != jsonMedia.end(); ++it){
            object = (*it).toObject();
            unsigned int currentId = object.value("id").toInt();

            if(currentId == id) return JsonToItem(object);
        }
    }
    
    return nullptr;


}

AbstractMedia* JsonStorage::JsonToItem(const QJsonObject& object){
    QJsonValue type = object.value("type");

    if(type.toString() == "album"){
        Album* a = new Album(
            object.value("id").toInt(), 
            object.value("pblDate").toInt(),
            object.value("title").toString().toStdString(), 
            object.value("author").toString().toStdString(),
            object.value("descr").toString().toStdString(),
            object.value("pathToImage").toString().toStdString()
        );

        QStringList tracklist = object.value("tracklist").toVariant().toStringList();
        const AbstractMedia* tmp = nullptr;

        for(const QString& s: tracklist){
            if(repository.count(s.toInt()) == 0){
                tmp = fetchObject(s.toInt());
                if(tmp) repository[s.toInt()] = tmp;
            }
            if(tmp) a->add(*(dynamic_cast<const Song*>(repository[s.toInt()])));
            
           
        }

        return a;
    }

    else if(type.toString() == "article"){
        return new Article(
            object.value("id").toInt(), 
            object.value("pblDate").toInt(),
            object.value("title").toString().toStdString(), 
            object.value("author").toString().toStdString(),
            object.value("descr").toString().toStdString(),
            object.value("pathToImage").toString().toStdString(),
            object.value("magazine").toString().toStdString()
        );
    }

    else if(type.toString() == "book"){
        return new Book(
            object.value("id").toInt(), 
            object.value("pblDate").toInt(),
            object.value("title").toString().toStdString(), 
            object.value("author").toString().toStdString(),
            object.value("descr").toString().toStdString(),
            object.value("pathToImage").toString().toStdString(),
            object.value("pages").toInt(),
            object.value("isbn").toString().toStdString()
        );
    }
    
    else if(type.toString() == "film"){
        return new Film(
            object.value("id").toInt(), 
            object.value("pblDate").toInt(),
            object.value("title").toString().toStdString(), 
            object.value("author").toString().toStdString(),
            object.value("descr").toString().toStdString(),
            object.value("pathToImage").toString().toStdString(),
            object.value("length").toInt(),
            object.value("country").toString().toStdString()
        );
    }

    else if(type.toString() == "song"){
        return new Song(
            object.value("id").toInt(), 
            object.value("pblDate").toInt(),
            object.value("title").toString().toStdString(), 
            object.value("author").toString().toStdString(),
            object.value("descr").toString().toStdString(),
            object.value("pathToImage").toString().toStdString(),
            object.value("length").toInt(),
            object.value("genre").toString().toStdString()
        );
    }

    return nullptr;
}

unsigned int JsonStorage::getMaxKey() const{
    return repository.rbegin()->first;
}

JsonStorage& JsonStorage::setFilePath(std::string path){
    filePath = path;

    return *this;
}

std::string JsonStorage::getFilePath() const{
    return filePath;
}



}
}
