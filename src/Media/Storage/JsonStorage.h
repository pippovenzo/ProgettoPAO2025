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
        explicit JsonStorage(std::string);
        
        //methods for the map
        JsonStorage& create(AbstractMedia& item);
        const AbstractMedia* read(unsigned int) const;
        JsonStorage& update(AbstractMedia& item);
        JsonStorage& remove(unsigned int id);

        //methods for the json file
        JsonStorage& flushToFile();
        JsonStorage& fetchFromFile();

        //Service methods
        unsigned int getMaxKey() const;
        std::vector<const AbstractMedia*> extract() const;

        //getter & setter
        JsonStorage& setFilePath(std::string);
        std::string getFilePath() const;
        
    private:
        std::map<unsigned int, const AbstractMedia*> repository;
        JsonVisitor storageVisitor;
        std::string filePath;
        

        //conversion methods
        QJsonObject itemToJson(const AbstractMedia&);
        AbstractMedia* JsonToItem(const QJsonObject&);
        
        const AbstractMedia* fetchObject(unsigned int);

};

}

}


#endif