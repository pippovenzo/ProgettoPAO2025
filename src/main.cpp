#include "Media/Album.h"
#include "Media/Song.h"
#include "Media/Storage/JsonStorage.h"
#include "View/MainWindow.h"

#include <iostream>
#include <QApplication>

using namespace media;
using namespace storage;
using namespace std;

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    /*Album a = Album(1, 2022, "Mafia Slime", "Nerissima Serpe", " ", "/ciao");
    Song s1 = Song(2, 2022, "Fratellini della chiesa", "Nerissima Serpe", " ", "/ciao", 120, "rap");
    Song s2 = Song(3, 2022, "Drive By", "Nerissima Serpe", " ", "/ciao", 120, "rap");

    a.add(s1);
    a.add(s2);*/

    view::MainWindow ciao = view::MainWindow();
    ciao.resize(1024, 576);
    ciao.show();

    return app.exec();

    

}