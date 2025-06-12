#include "View/MainWindow.h"

#include <iostream>
#include <QApplication>

using namespace media;
using namespace storage;
using namespace std;

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    app.setWindowIcon(QIcon(":/src/assets/icons/app_icon.png")); 

    view::MainWindow mainWindow = view::MainWindow();
    mainWindow.resize(1024, 576);
    mainWindow.show();

    return app.exec();

    

}