#include "JsonVisitor.h"
#include <QJsonObject>
#include <QStringList>
#include "../Song.h"
#include <vector>


namespace media{
namespace storage
{

QJsonObject JsonVisitor::getObject() const{ 
    return object; 
}

void JsonVisitor::visit(const Album &a){
    QJsonObject albumJson;
    QStringList tracklistJson;
    std::vector<const Song*> tracklist = a.getTracklist();

    for(auto it = tracklist.begin(); it != tracklist.end(); ++it){
        tracklistJson.append(QString::number((*it)->getId()));
    }
    
    albumJson.insert("type", QJsonValue::fromVariant("album"));
    albumJson.insert("id", QJsonValue::fromVariant(a.getId()));
    albumJson.insert("pblDate", QJsonValue::fromVariant(a.getPblDate()));
    albumJson.insert("title", QJsonValue::fromVariant(QString::fromStdString(a.getTitle())));
    albumJson.insert("author", QJsonValue::fromVariant(QString::fromStdString(a.getAuthor())));
    albumJson.insert("descr", QJsonValue::fromVariant(QString::fromStdString(a.getDescr())));
    albumJson.insert("pathToImage", QJsonValue::fromVariant(QString::fromStdString(a.getImagePath())));
    albumJson.insert("tracklist", QJsonValue::fromVariant(tracklistJson));
    
    object = albumJson;
}

void JsonVisitor::visit(const Article &a){
    QJsonObject articleJson;
    
    articleJson.insert("type", QJsonValue::fromVariant("article"));
    articleJson.insert("id", QJsonValue::fromVariant(a.getId()));
    articleJson.insert("pblDate", QJsonValue::fromVariant(a.getPblDate()));
    articleJson.insert("title", QJsonValue::fromVariant(QString::fromStdString(a.getTitle())));
    articleJson.insert("author", QJsonValue::fromVariant(QString::fromStdString(a.getAuthor())));
    articleJson.insert("descr", QJsonValue::fromVariant(QString::fromStdString(a.getDescr())));
    articleJson.insert("pathToImage", QJsonValue::fromVariant(QString::fromStdString(a.getImagePath())));
    articleJson.insert("magazine", QJsonValue::fromVariant(QString::fromStdString(a.getMagazine())));
    
    object = articleJson;
}

void JsonVisitor::visit(const Book &b){
    QJsonObject bookJson;
    
    bookJson.insert("type", QJsonValue::fromVariant("book"));
    bookJson.insert("id", QJsonValue::fromVariant(b.getId()));
    bookJson.insert("pblDate", QJsonValue::fromVariant(b.getPblDate()));
    bookJson.insert("title", QJsonValue::fromVariant(QString::fromStdString(b.getTitle())));
    bookJson.insert("author", QJsonValue::fromVariant(QString::fromStdString(b.getAuthor())));
    bookJson.insert("descr", QJsonValue::fromVariant(QString::fromStdString(b.getDescr())));
    bookJson.insert("pathToImage", QJsonValue::fromVariant(QString::fromStdString(b.getImagePath())));
    bookJson.insert("pages", QJsonValue::fromVariant(b.getPages()));
    bookJson.insert("isbn", QJsonValue::fromVariant(QString::fromStdString(b.getIsbn())));
    
    object = bookJson;
}

void JsonVisitor::visit(const Film &f){
    QJsonObject filmJson;
    
    filmJson.insert("type", QJsonValue::fromVariant("film"));
    filmJson.insert("id", QJsonValue::fromVariant(f.getId()));
    filmJson.insert("pblDate", QJsonValue::fromVariant(f.getPblDate()));
    filmJson.insert("title", QJsonValue::fromVariant(QString::fromStdString(f.getTitle())));
    filmJson.insert("author", QJsonValue::fromVariant(QString::fromStdString(f.getAuthor())));
    filmJson.insert("descr", QJsonValue::fromVariant(QString::fromStdString(f.getDescr())));
    filmJson.insert("pathToImage", QJsonValue::fromVariant(QString::fromStdString(f.getImagePath())));
    filmJson.insert("length", QJsonValue::fromVariant(f.getLength()));
    filmJson.insert("country", QJsonValue::fromVariant(QString::fromStdString(f.getCountry())));
    
    object = filmJson;
}   

void JsonVisitor::visit(const Song &s){
    QJsonObject songJson;
    
    songJson.insert("type", QJsonValue::fromVariant("song"));
    songJson.insert("id", QJsonValue::fromVariant(s.getId()));
    songJson.insert("pblDate", QJsonValue::fromVariant(s.getPblDate()));
    songJson.insert("title", QJsonValue::fromVariant(QString::fromStdString(s.getTitle())));
    songJson.insert("author", QJsonValue::fromVariant(QString::fromStdString(s.getAuthor())));
    songJson.insert("descr", QJsonValue::fromVariant(QString::fromStdString(s.getDescr())));
    songJson.insert("pathToImage", QJsonValue::fromVariant(QString::fromStdString(s.getImagePath())));
    songJson.insert("length", QJsonValue::fromVariant(s.getLength()));
    songJson.insert("genre", QJsonValue::fromVariant(QString::fromStdString(s.getGenre())));
    
    object = songJson;
}

}
}