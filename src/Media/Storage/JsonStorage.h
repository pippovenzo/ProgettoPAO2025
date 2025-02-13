#ifndef JSON_STORAGE_H
#define JSON_STORAGE_H

#include <map>
#include <string>
#include <QJsonDocument>
#include <QJsonObject>

#include "../AbstractMedia.h"
#include "JsonVisitor.h"

namespace media
{
namespace storage
{

class JsonStorage{

    public: 
        JsonStorage();
        
        //methods for the map
        JsonStorage& create(AbstractMedia& item);
        JsonStorage& read(unsigned int id);
        JsonStorage& update(AbstractMedia& item);
        JsonStorage& remove(unsigned int id);

        //methods for the json file
        JsonStorage& flushToFile();
        JsonStorage& fetchFromFile();
    private:
        JsonVisitor storageVisitor;
        //static std::string filePath;
        std::map<unsigned int, AbstractMedia*> storage;
        
        //conversion methods
        QJsonObject itemToJson(AbstractMedia&);
        std::vector<const AbstractMedia*> extract();

};

}

}


#endif