#include "Album.h"
#include "Song.h"

using namespace media;

int main(){
    Album a = Album(1, 2022, "Mafia Slime", "Nerissima Serpe", " ", "/ciao");
    Song s1 = Song(2, 2022, "Fratellini della chiesa", "Nerissima Serpe", " ", "/ciao", 120, "rap");

    a.add(s1);
    a.print();
    a.remove(0);
    a.print();



}