#include "Album.h"
#include "Song.h"
#include "Storage/JsonStorage.h"
#include <iostream>

using namespace media;
using namespace storage;
using namespace std;

int main(){
    Album a = Album(1, 2022, "Mafia Slime", "Nerissima Serpe", " ", "/ciao");
    Song s1 = Song(2, 2022, "Fratellini della chiesa", "Nerissima Serpe", " ", "/ciao", 120, "rap");
    Song s2 = Song(3, 2022, "Drive By", "Nerissima Serpe", " ", "/ciao", 120, "rap");

    a.add(s1);
    a.add(s2);
    //a.print();
    //a.remove(0);
    //a.print();

    JsonStorage sto;
    
    /*storage.create(a);
    storage.create(s1);
    storage.create(s2);

    storage.flushToFile();*/

    /*sto.fetchFromFile();

    vector<const Song*> ciao = (dynamic_cast<const Album*>(sto.repository[1]))->getTracklist();
    for(auto it = ciao.begin(); it != ciao.end(); ++it){
        cout << (*it)->getTitle() << endl;
    }
    cout << sto.repository[1]->getTitle();
    cout << sto.repository[2]->getTitle();
    cout << sto.repository[3]->getTitle();*/

}