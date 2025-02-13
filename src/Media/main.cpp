#include "Album.h"
#include "Song.h"
#include "Storage/JsonStorage.h"

using namespace media;
using namespace storage;

int main(){
    Album a = Album(1, 2022, "Mafia Slime", "Nerissima Serpe", " ", "/ciao");
    Song s1 = Song(2, 2022, "Fratellini della chiesa", "Nerissima Serpe", " ", "/ciao", 120, "rap");
    Song s2 = Song(3, 2022, "Drive By", "Nerissima Serpe", " ", "/ciao", 120, "rap");

    a.add(s1);
    a.add(s2);
    //a.print();
    //a.remove(0);
    //a.print();

    JsonStorage storage;

    storage.create(a);
    storage.create(s1);
    storage.create(s2);

    storage.flushToFile();



}